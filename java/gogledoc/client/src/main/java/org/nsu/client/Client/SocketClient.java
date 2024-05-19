package org.nsu.client.Client;

import org.nsu.client.Logger.ClientLoggerFinder;
import org.nsu.client.Utils.CodeUtil;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.ServerSocketChannel;
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
        String msg = "{\"user\": \"root\", \"type\": \"i\", \"position\": 2, \"cursor_end\": 4, \"content\": \"ab\"}";
        try {
            server.write(CodeUtil.bufferFromString(msg));
            logger.log(System.Logger.Level.DEBUG, "wrote");
            while (server.read(buffer) > 0) {
                logger.log(System.Logger.Level.DEBUG, "begin");
                buffer.flip();
                String s = CodeUtil.stringFromBuffer(buffer);
                System.out.println(s);
                buffer.clear();
                logger.log(System.Logger.Level.DEBUG, "end");
            }
            logger.log(System.Logger.Level.DEBUG, "exit");
            server.close();
            logger.log(System.Logger.Level.INFO, "sent");
        } catch (IOException ioException) {
            logger.log(System.Logger.Level.ERROR, ioException);
        }
    }
}
