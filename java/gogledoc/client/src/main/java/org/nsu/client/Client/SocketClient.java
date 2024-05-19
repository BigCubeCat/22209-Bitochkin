package org.nsu.client.Client;

import org.nsu.client.Logger.ClientLoggerFinder;
import org.nsu.client.Utils.CodeUtil;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;

public class SocketClient {
    private final System.Logger logger = ClientLoggerFinder.getLogger("server", this.getClass().getModule());

    int port;
    SocketChannel server = null;
    SocketAddress socketAddress = null;

    ByteBuffer buffer = ByteBuffer.allocate(1024);

    public SocketClient(int port) {
        this.port = port;
        try {
            server = SocketChannel.open();
            socketAddress = new InetSocketAddress("localhost", this.port);
            server.connect(socketAddress);
        } catch (IOException e) {
            logger.log(System.Logger.Level.ERROR, e);
        }
    }

    public void Run() {
        String msg1 = "{\"user\": \"root\", \"type\": \"j\", \"position\": 1}";
        String msg2 = "{\"user\": \"root\", \"type\": \"d\", \"cursor_end\": 4}";
        while (true) {
            try {
                Thread.sleep(1000);
                if (Math.random() < 0.8)
                    server.write(CodeUtil.bufferFromString(msg1));
                else
                    server.write(CodeUtil.bufferFromString(msg2));
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
