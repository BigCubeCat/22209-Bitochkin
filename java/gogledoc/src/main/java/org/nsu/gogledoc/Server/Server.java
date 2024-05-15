package org.nsu.gogledoc.Server;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;

public class Server {
    private int port;
    private int bufferSize;

    private ServerSocketChannel server;
    private Selector selector;
    ByteBuffer buffer;

    private ArrayList<Conn> clients;

    public Server(int port, int bufferSize) {
        this.port = port;
        this.bufferSize = bufferSize;
        try {
            server = ServerSocketChannel.open();
            server.socket().bind(new InetSocketAddress(this.port));
            server.socket().setReuseAddress(true);
            server.configureBlocking(false);

            selector = Selector.open();
            server.register(selector, SelectionKey.OP_ACCEPT);

            buffer = ByteBuffer.allocate(this.bufferSize);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Server(int port) {
        this(port, 256);
    }

    public Server() {
        this(8080);
    }

    public static String stringFromBuffer(ByteBuffer buffer) {
        return StandardCharsets.UTF_8.decode(buffer).toString();
    }

    public static ByteBuffer bufferFromString(String string) {
        return StandardCharsets.UTF_8.encode(string);
    }

    public void RunServer() {
        int channelCount;
        while (true) {
            try {
                channelCount = selector.select();
                if (channelCount > 0) {
                    Set<SelectionKey> keys = selector.selectedKeys();
                    Iterator<SelectionKey> iterator = keys.iterator();
                    while (iterator.hasNext()) {
                        SelectionKey key = iterator.next();
                        iterator.remove();

                        if (key.isAcceptable()) {
                            SocketChannel client = server.accept();
                            client.configureBlocking(false);
                            client.register(
                                    selector,
                                    SelectionKey.OP_READ,
                                    client.socket().getPort()
                            );
                        } else if (key.isReadable()) {
                            SocketChannel client = (SocketChannel) key.channel();
                            if (client.read(buffer) < 0) {
                                key.cancel();
                                client.close();
                            } else {
                                buffer.flip();

                                String request = stringFromBuffer(buffer);
                                System.out.println(request);
                                client.write(bufferFromString(request));

                                buffer.clear();
                            }
                        }
                    }
                }
            } catch (IOException _e) {
                continue;
            }
        }
    }

    private void connectClient() throws IOException {
        SocketChannel client = server.accept();
        client.configureBlocking(false);
        Conn conn = new Conn(client);
        clients.add(conn);
    }
}
