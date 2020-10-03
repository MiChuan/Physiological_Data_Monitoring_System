package application;

import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import java.net.URL;
import java.sql.*;
import java.time.LocalDate;
import java.util.*;

/**
 * 发布消息的回调类
 *
 * 必须实现MqttCallback的接口并实现对应的相关接口方法CallBack 类将实现 MqttCallBack。
 * 每个客户机标识都需要一个回调实例。在此示例中，构造函数传递客户机标识以另存为实例数据。
 * 在回调中，将它用来标识已经启动了该回调的哪个实例。
 * 必须在回调类中实现三个方法：
 *
 *  public void messageArrived(MqttTopic topic, MqttMessage message)接收已经预订的发布。
 *
 *  public void connectionLost(Throwable cause)在断开连接时调用。
 *
 *  public void deliveryComplete(MqttDeliveryToken token))
 *  接收到已经发布的 QoS 1 或 QoS 2 消息的传递令牌时调用。
 *  由 MqttClient.connect 激活此回调。
 *
 */
public class PushCallback implements MqttCallback {
    static final String DB_URL = "jdbc:mysql://47.106.172.87:3306/RFID_DESIGN?useUnicode=true&characterEncoding=utf-8&useSSL=false";
    static final String USER = "root";
    static final String PASSWORD = "512013";
    static Connection connection = null;
    static Statement statement = null;

    public void connectionLost(Throwable cause) {

        // 连接丢失后，一般在这里面进行重连
        System.out.println("连接断开，可以做重连");
    }

    public void deliveryComplete(IMqttDeliveryToken token) {
        System.out.println("deliveryComplete---------" + token.isComplete());
    }

    public void messageArrived(String topic, MqttMessage message) throws Exception {
        // subscribe后得到的消息会执行到这里面
        System.out.println("接收消息主题 : " + topic);
        System.out.println("接收消息Qos : " + message.getQos());
        System.out.println("接收消息内容 : " + new String(message.getPayload()));

        String physiologicalData = new String(message.getPayload());
        String[] eachData = physiologicalData.split(",");//切分数据
        try {
            //1--加载驱动
            Class.forName("com.mysql.jdbc.Driver");
            //2--建立数据库连接
            connection = DriverManager.getConnection(DB_URL,USER,PASSWORD);
            //3--使用Connection 对象创建Statement，为传递sql语句做准备
            statement = connection.createStatement();
            //4--通过Statement对象传递sql语句
            String sql = "INSERT INTO temperature_data(savetime,temperature) VALUE("
                            + "'"+eachData[0]+"',"+eachData[1]+")";
            statement.executeQuery(sql);
            sql = "INSERT INTO heartrate_data(savetime,heartrate) VALUE(" + "'"+eachData[0]+"',"+eachData[2]+")";
            statement.executeQuery(sql);
            sql = "INSERT INTO bloodpressure_data(savetime,SBP,DBP) VALUE("
                    + "'"+eachData[0]+"',"+eachData[3]+","+eachData[4]+")";
            statement.executeQuery(sql);
            //5--关闭所有连接 必须从后面往前面关
            statement.close();
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        //for(String str : eachData) System.out.println(str);
    }
}
