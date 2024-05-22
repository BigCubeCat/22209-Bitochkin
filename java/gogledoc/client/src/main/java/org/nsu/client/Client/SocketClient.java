package org.nsu.client.Client;

import org.nsu.client.Controller.Data;
import org.nsu.client.Logger.ClientLoggerFinder;
import org.nsu.client.Utils.CodeUtil;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;
import java.util.Random;

public class SocketClient implements Runnable {
    private final System.Logger logger = ClientLoggerFinder.getLogger("server", this.getClass().getModule());

    int port;
    Data data;

    SocketChannel server = null;
    SocketAddress socketAddress = null;

    ByteBuffer buffer = ByteBuffer.allocate(1024);

    public SocketClient(Data data, int port) {
        this.data = data;
        this.port = port;
        try {
            server = SocketChannel.open();
            socketAddress = new InetSocketAddress("localhost", this.port);
            server.connect(socketAddress);
        } catch (IOException e) {
            logger.log(System.Logger.Level.ERROR, e);
        }
    }

    public static String getRandom(String[] array) {
        int rnd = new Random().nextInt(array.length);
        return array[rnd];
    }

    @Override
    public void run() {
        String msg1 = "{\"user\": \"root\", \"type\": \"j\", \"position\": 1}";
        String msg2 = "{\"user\": \"user\", \"type\": \"j\", \"position\": 0}";
        String msg3 = "{\"user\": \"user\", \"type\": \"i\", \"position\": 0, \"content\": \"a\"}";
        String msg4 = "{\"user\": \"u\", \"type\": \"u\", \"unixtime\": 0}";
        String[] messages = {msg1, msg2, msg3, msg4};
        while (true) {
            try {
                String msg = getRandom(messages);
                System.out.println(msg);
                Thread.sleep(1000);
                server.write(CodeUtil.bufferFromString(msg));
                logger.log(System.Logger.Level.DEBUG, "wrote");
                int n;
                n = server.read(buffer);
                logger.log(System.Logger.Level.DEBUG, "r " + n);
                buffer.flip();
                String s = CodeUtil.stringFromBuffer(buffer);
                System.out.println(s);
                buffer.clear();
                logger.log(System.Logger.Level.DEBUG, "end");
            } catch (IOException ioException) {
                logger.log(System.Logger.Level.ERROR, ioException);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
