package application;

import java.sql.*;
import java.text.MessageFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.ScheduledExecutorService;

import org.eclipse.paho.client.mqttv3.*;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

import static java.lang.Thread.sleep;

/**
 * 模拟一个客户端接收消息
 *
 * @author huhan
 */
public class SubscribeClient {
    public static final String HOST = "tcp://47.106.172.87:1883";
    public static final String TOPIC1 = "physiology_data";
    private static final String clientid = "SubscribeClient";
    private MqttClient client;
    private MqttConnectOptions options;
    private String userName = "mqtt";    //非必须
    private String passWord = "mqtt";  //非必须
    private ScheduledExecutorService scheduler;
    //数据库
    static final String DB_URL = "jdbc:mysql://47.106.172.87:3306/RFID_DESIGN?useUnicode=true&characterEncoding=utf-8&useSSL=false";
    static final String USER = "root";
    static final String PASSWORD = "512013";
    static Connection connection = null;
    static Statement statement = null;
    int count = 0;

    private void start() {
        try {
            // host为主机名，clientid即连接MQTT的客户端ID，一般以唯一标识符表示，MemoryPersistence设置clientid的保存形式，默认为以内存保存
            client = new MqttClient(HOST, clientid, new MemoryPersistence());
            // MQTT的连接设置
            options = new MqttConnectOptions();
            // 设置是否清空session,这里如果设置为false表示服务器会保留客户端的连接记录，设置为true表示每次连接到服务器都以新的身份连接
            options.setCleanSession(false);
            // 设置连接的用户名
            options.setUserName(userName);
            // 设置连接的密码
            options.setPassword(passWord.toCharArray());
            // 设置超时时间 单位为秒
            options.setConnectionTimeout(100);
            // 设置会话心跳时间 单位为秒 服务器会每隔1.5*20秒的时间向客户端发送个消息判断客户端是否在线，但这个方法并没有重连的机制
            options.setKeepAliveInterval(20);
            //设置断开后重新连接
            options.setAutomaticReconnect(true);
            // 设置回调
            //client.setCallback(new PushCallback());
            client.setCallback(new MqttCallback() {
                public void connectionLost(Throwable throwable) {
                    // 连接丢失后，一般在这里面进行重连
                    System.out.println("连接断开，可以做重连");
                }

                public void messageArrived(String topic, MqttMessage message) throws Exception {
                    // subscribe后得到的消息会执行到这里面
                    String physiologicalData = new String(message.getPayload());
//                    System.out.println("接收消息主题 : " + topic);
//                   //System.out.println("接收消息Qos : " + message.getQos());
//                    System.out.println("接收消息内容: " + physiologicalData);

                    String[] eachData = physiologicalData.split(",");//切分数据
                    //sleep(3000);

                    try {
                        //2--建立数据库连接
                        connection = DriverManager.getConnection(DB_URL,USER,PASSWORD);
                        //3--使用Connection 对象创建Statement，为传递sql语句做准备
                        statement = connection.createStatement();

                        //4--通过Statement对象传递sql语句
                        String sql = "SELECT * FROM temperature_data WHERE savetime=" + "'"+eachData[0]+"'";
                        ResultSet result = statement.executeQuery(sql);
                        if(result.next()){

                        } else{
                            System.out.println("接收消息主题 : " + topic);
                            //System.out.println("接收消息Qos : " + message.getQos());
                            System.out.println("接收消息内容: " + physiologicalData);

                            sql = "INSERT INTO temperature_data(savetime,temperature) VALUE("
                                    + "'"+eachData[0]+"',"+eachData[1]+")";
                            statement.execute(sql);

                            sql = "INSERT INTO heartrate_data(savetime,heartrate) VALUE(" + "'"+eachData[0]+"',"+eachData[2]+")";
                            statement.execute(sql);

                            sql = "INSERT INTO bloodpressure_data(savetime,SBP,DBP) VALUE("
                                    + "'"+eachData[0]+"',"+eachData[3]+","+eachData[4]+")";
                            statement.execute(sql);
                        }

                        //5--关闭所有连接 必须从后面往前面关
                        statement.close();
                        connection.close();
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                }

                public void deliveryComplete(IMqttDeliveryToken iMqttDeliveryToken) {

                }
            });
            MqttTopic topic = client.getTopic(TOPIC1);
            //setWill方法，如果项目中需要知道客户端是否掉线可以调用该方法。设置最终端口的通知消息
            //遗嘱
            //options.setWill(topic, "close".getBytes(), 1, true);
            client.connect(options);
            //订阅消息
            int[] Qos = {1};//0：最多一次 、1：最少一次 、2：只有一次
            String[] topic1 = {TOPIC1};
            client.subscribe(topic1, Qos);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args)  throws Exception {
        //1--加载驱动
        Class.forName("com.mysql.jdbc.Driver");
        SubscribeClient subscribeClient = new SubscribeClient();
        subscribeClient.start();
    }
}
