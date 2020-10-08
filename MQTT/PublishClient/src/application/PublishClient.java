package application;

import java.util.Timer;
import java.util.TimerTask;

import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.MqttPersistenceException;
import org.eclipse.paho.client.mqttv3.MqttTopic;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

import application.PushCallback;//回调类
import javafx.scene.chart.PieChart.Data;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.math.BigDecimal;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;
import static java.lang.Thread.sleep;
import static java.math.BigDecimal.ROUND_HALF_DOWN;

import javax.microedition.io.Connector;
import javax.microedition.io.StreamConnection;
import javax.microedition.io.StreamConnectionNotifier;

/**
 * 传感器模拟
 * @author huhan
 * */
class TemperatureSensor {
    private double voltage;
    private double temperature;
    private int mode;//体温范围，0代表正常，1代表发烧
    public final int normal = 0;
    public final int feverT = 38;
    private final double feverV = 905.109; //36.5~37.3正常体温,高于37.3发烧
    private final double lowV = 909.797;
    private final double highV = 880.630;

    /**
     * 采用饿汉式单例模式创建传感器实例
     * */
    private static final TemperatureSensor temperatureSensor = new TemperatureSensor();

    private TemperatureSensor() {
        this.mode = 0;
        this.voltage = 0;
        this.temperature = 0;
    }

    //静态工厂方法
    public static TemperatureSensor getInstance() {
        return temperatureSensor;
    }

    public void setMode(int mode) {
        this.mode = mode;
    }

    private void generateVoltage() {
        Random ra = new Random();
        if(mode == normal){
            voltage = ra.nextDouble() * (feverV - lowV) + lowV;
        }
        else voltage = ra.nextDouble() * (highV - feverV) + feverV;
    }

    private void trans() {
        temperature = -0.192 * voltage + 211.081;
    }

    public double getTemperature() {
        generateVoltage();
        trans();
        return temperature;
    }

    @Override
    public String toString() {
        return "温度传感器 型号：德州仪器 LMT70";
    }
}

class HeartRateSensor {
    private int BPM;
    private double IBI;
    private int mode;//心率范围, 0为正常, 负数为过慢, 正数为过快
    public final int normal = 0;
    public final int quickRate = 1;
    public final int slowRate = -1;
    private final double slowH = 2;//30~60过慢, 60~100正常, 100~160过快
    private final double quickH = 0.375;
    private final double lowH = 0.87;
    private final double highH = 0.65;

    /**
     * 采用饿汉式单例模式创建传感器实例
     * */
    private static final HeartRateSensor heartRateSensor = new HeartRateSensor();

    private HeartRateSensor() {
        this.BPM = 0;
        this.IBI = 0;
        this.mode = 0;
    }

    //静态工厂方法
    public static HeartRateSensor getInstance() {
        return heartRateSensor;
    }

    public void setMode(int mode) {
        this.mode = mode;
    }

    private void generateIBI() {
        Random ra = new Random();
        if(mode < normal) IBI = ra.nextDouble() * (slowH - lowH) + lowH;//过慢
        else if(mode > normal) IBI = ra.nextDouble() * (highH - quickH) + quickH;//过快
        else IBI = ra.nextDouble() * (lowH - highH) + highH;//正常
    }

    private void trans() {
        BPM = (int) (60 / IBI);
    }

    public int getBPM() {
        generateIBI();
        trans();
        return BPM;
    }

    @Override
    public String toString() {
        return "心率传感器 型号：汇顶科技 GH301";
    }
}

class BloodPressureSensor {
    private double SBP;
    private double DBP;
    private double SBP_Hg;
    private double DBP_Hg;
    public int mode;
    public final int normal = 0;//收缩压高于140mmHg, 舒张压高于90mmHg为高血压
    public final int highBloodPressure = 1;
    private final double lowSBP = 13.4;
    private final double highSBP = 17.3;
    private final double highPressureSBP = 25;
    private final double lowDBP = 8.7;
    private final double highDBP = 10.7;
    private final double highPressureDBP = 20;

    /**
     * 采用饿汉式单例模式创建传感器实例
     * */
    private static final BloodPressureSensor bloodPressureSensor = new BloodPressureSensor();

    private BloodPressureSensor() {
        this.SBP = 0;
        this.DBP = 0;
        this.SBP_Hg = 0;
        this.DBP_Hg = 0;
        this.mode = 0;
    }

    //静态工厂方法
    public static BloodPressureSensor getInstance() {
        return bloodPressureSensor;
    }

    public void setMode(int mode) {
        this.mode = mode;
    }

    private void generatePressure() {
        Random ra = new Random();
        if(mode == normal){
            SBP = ra.nextDouble() * (highSBP - lowSBP) + lowSBP;//正常
            DBP = ra.nextDouble() * (highDBP - lowDBP) + lowDBP;
        } else {
            SBP = ra.nextDouble() * (highPressureSBP - lowSBP) + lowSBP;//高收缩压
            DBP = ra.nextDouble() * (highPressureDBP - lowDBP) + lowDBP;//高舒张压
        }
    }

    private void trans() {
        SBP_Hg = SBP * 7.5;
        DBP_Hg = DBP * 7.5;
    }

    public double getSBP() {
        generatePressure();
        trans();
        return SBP_Hg;
    }

    public double getDBP() {
        generatePressure();
        trans();
        return DBP_Hg;
    }

    @Override
    public String toString() {
        return "血压传感器 型号：苏州敏芯微电子 MSP40-G系列";
    }
}

class SensorSimulate{
    private TemperatureSensor t;
    private HeartRateSensor h;
    private BloodPressureSensor b;

    /**
     * 采用饿汉式单例模式创建传感器模拟器实例
     * */
    private static final SensorSimulate sensorSimulate = new SensorSimulate();

    private SensorSimulate() {
        this.t = TemperatureSensor.getInstance();
        this.h = HeartRateSensor.getInstance();
        this.b = BloodPressureSensor.getInstance();
    }

    //静态工厂方法
    public static SensorSimulate getInstance() {
        return sensorSimulate;
    }

    @Override
    public String toString() {//模拟器描述
        return this.t + "\n" + this.h + "\n" + this.b + "\n";
    }

    public String generateData(){
        String physiologicalData  = "";

        t.setMode(t.normal);
        double temperature = t.getTemperature();
        int precimal = 1;
        temperature = new BigDecimal(temperature).setScale(precimal, ROUND_HALF_DOWN).doubleValue();
        physiologicalData += temperature;

        h.setMode(h.normal);
        int heartRate = h.getBPM();
        physiologicalData = physiologicalData + "," + heartRate;

        b.setMode(b.normal);
        double SBP = b.getSBP();
        double DBP = b.getDBP();
        SBP = new BigDecimal(SBP).setScale(precimal, ROUND_HALF_DOWN).doubleValue();
        DBP = new BigDecimal(DBP).setScale(precimal, ROUND_HALF_DOWN).doubleValue();
        physiologicalData = physiologicalData + "," + SBP + "," + DBP;
        //System.out.println(physiologicalData);//采集的三类数据整合成一个字符串
        return physiologicalData;
    }

    /*public static void main(String args[]) throws InterruptedException {
        SensorSimulate sensor = SensorSimulate.getInstance();
        System.out.println(sensor);
        for(int count = 10; count > 0; --count) {
            System.out.println(sensor.generateData());
            sleep(5000);
        }

        
        String[] eachData = physiologicalData.split(" ");//切分三类数据
        
        
    }*/
}

/**
 * Title:Server 这是发送消息的客户端
 * Description: 向多个客户端推送主题
 * @author huhan
 */

public class PublishClient {
	//传感器模拟器
	private static SensorSimulate sensor = SensorSimulate.getInstance();
	
	//tcp://MQTT安装的服务器地址:MQTT定义的端口号
    public static final String HOST = "tcp://47.106.172.87:1883";
    //定义主题
    public static final String TOPIC1 = "physiology_data";
    
    //定义MQTT的ID，可以在MQTT服务配置中指定
    private static final String clientid = "PublishClient";
 
    private MqttClient client;
    private static MqttTopic topic11;

//    private String userName = "Publish";  //非必须
//    private String passWord = "512013";  //非必须
 
    private static MqttMessage message;
 
    /**
     * 构造函数
     * @throws MqttException
     */
    public PublishClient(){
        
    }
    
    /**
     *  用来连接服务器
     */
    private void connect() throws MqttException {
    	// MemoryPersistence设置clientid的保存形式，默认为以内存保存
        client = new MqttClient(HOST, clientid, new MemoryPersistence());
        MqttConnectOptions options = new MqttConnectOptions();
        options.setCleanSession(false);
//        options.setUserName(userName);
//        options.setPassword(passWord.toCharArray());
        // 设置超时时间
        options.setConnectionTimeout(10);
        // 设置会话心跳时间
        options.setKeepAliveInterval(20);
        try {
            client.setCallback(new PushCallback());
            client.connect(options);
            topic11 = client.getTopic(TOPIC1);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    /**
     *  启动入口
     * @param args
     * @throws MqttException
     */
    public static void main(String[] args) throws Exception {
    	System.out.println(sensor);
        PublishClient server = new PublishClient();
        server.connect();
        
        TimerTask task = new TimerTask() {
            @Override
            public void run() {
            	Date d = new Date();
            	SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        		String dateNowStr = sdf.format(d);
        		//生成消息内容
            	String content = dateNowStr + "," + sensor.generateData();
            	System.out.println(content);
                
                server.message = new MqttMessage();
                server.message.setQos(1);  //保证消息能到达一次
                server.message.setRetained(true);//保留消息
                //server.message.setRetained(false);//保留消息
                server.message.setPayload(content.getBytes());//消息内容
                try{
                    //publish(server.message);
                    MqttDeliveryToken token = topic11.publish(message);
                    
                    token.waitForCompletion();
                    System.out.println("message is published completely! "
                            + token.isComplete());
                    //断开连接
                    //server.client.disconnect();
                }catch (Exception e){
                    e.printStackTrace();
                }
            }
        };
        Timer t = new Timer();
        long delay = 1000;
        long intevalTime = 10000; //采集数据间隔10秒
        t.scheduleAtFixedRate(task, delay, intevalTime);
    }
}
