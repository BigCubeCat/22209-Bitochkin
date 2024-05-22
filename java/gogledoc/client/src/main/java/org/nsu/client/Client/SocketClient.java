package org.nsu.client.Client;

import org.nsu.client.Controller.Data;
import org.nsu.client.Logger.ClientLoggerFinder;
import org.nsu.client.Utils.CodeUtil;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;

public class SocketClient implements Runnable {
    private final System.Logger logger = ClientLoggerFinder.getLogger("server", this.getClass().getModule());

    int port;
    Data clientToServer;
    Data serverToClient;

    SocketChannel server = null;
    SocketAddress socketAddress = null;

    ByteBuffer buffer = ByteBuffer.allocate(1024);

    public SocketClient(Data data1, Data data2, int port) {
        serverToClient = data1;
        clientToServer = data2;
        this.port = port;

        try {
            server = SocketChannel.open();
            socketAddress = new InetSocketAddress("localhost", this.port);
            server.connect(socketAddress);
        } catch (IOException e) {
            logger.log(System.Logger.Level.ERROR, e);
        }
    }

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(100);
                String message = clientToServer.consume();
                System.out.println(message);
                server.write(CodeUtil.bufferFromString(message));
                server.read(buffer);
                buffer.flip();
                String response = CodeUtil.stringFromBuffer(buffer);
                buffer.clear();
                serverToClient.produce(response);
            } catch (IOException ioException) {
                logger.log(System.Logger.Level.ERROR, ioException);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
