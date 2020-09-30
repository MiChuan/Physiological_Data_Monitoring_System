package application;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

import javax.microedition.io.Connector;
import javax.microedition.io.StreamConnection;
import javax.microedition.io.StreamConnectionNotifier;

/**
 * 蓝牙的服务器端。部署在Windows操作系统（PC电脑上）。 等待手机客户端或者其他蓝牙设备的连接。 该代码文件是一个Java
 * SE代码文件。运行于Windows PC上。
 * 
 * Java在Windows PC上实现蓝牙，必须依赖两个库： 
 * 
 * 1，bluecove-2.1.1-SNAPSHOT.jar
 * 下载：http://snapshot.bluecove.org/distribution/download/2.1.1-SNAPSHOT/2.1.1-SNAPSHOT.63/
 * 
 * 2，commons-io-2.6.jar
 * 下载：http://commons.apache.org/proper/commons-io/download_io.cgi
 * 
 * @author huhan
 *
 */
public class BluetoothJavaServer {
	private StreamConnectionNotifier mStreamConnectionNotifier = null;
	private StreamConnection mStreamConnection = null;

	public static void main(String[] args) {
		new BluetoothJavaServer();
	}

	public BluetoothJavaServer() {
		try {
			// 服务器端的UUID必须和手机端的UUID相一致。手机端的UUID需要去掉中间的-分割符。
			mStreamConnectionNotifier = (StreamConnectionNotifier) Connector
					.open("btspp://localhost:0000110100001000800000805F9B34FB");
		} catch (Exception e) {
			e.printStackTrace();
		}

		// 开启线程读写蓝牙上接收和发送的数据。
		new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					System.out.println("服务器端开始监听...");
					while (true) {
						mStreamConnection = mStreamConnectionNotifier.acceptAndOpen();
						System.out.println("接受连接");

						//InputStream inStream = mStreamConnection.openInputStream();
						//DataInputStream dataInSteam = new DataInputStream(inStream);
						OutputStream outStream = mStreamConnection.openOutputStream();
						DataOutputStream dataOutStream = new DataOutputStream(outStream);
						
						System.out.println("开始写数据...");
						String outString = "37.1 68 112.3 78.6";
						dataOutStream.writeUTF(outString);

						//System.out.println("开始读数据...");
						// 读数据。
						//String inString = dataInSteam.readUTF();
						//System.out.println(inString);

						outStream.close();
						//inStream.close();
						mStreamConnection.close();
					}
				} catch (Exception e) {
					e.printStackTrace();
				}
			}

		}).start();
	}
}
