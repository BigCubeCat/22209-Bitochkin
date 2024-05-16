package org.nsu.gogledoc.Server;

import org.nsu.gogledoc.Chat.Chat;
import org.nsu.gogledoc.Cmd.Cmd;
import org.nsu.gogledoc.Cmd.CmdParser;
import org.nsu.gogledoc.Cmd.CmdType;
import org.nsu.gogledoc.FileWorker.EditSession;
import org.nsu.gogledoc.Logger.ServerLoggerFinder;
import org.nsu.gogledoc.Utils.CodeUtil;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class Server {
    private final System.Logger logger = ServerLoggerFinder.getLogger("server", this.getClass().getModule());

    private int port;
    private int bufferSize;

    private CmdParser cmdParser = new CmdParser();
    private EditSession editSession;

    private Chat chat;

    private ServerSocketChannel server;
    private Selector selector;
    ByteBuffer buffer;

    private HashMap<SocketChannel, Conn> connHashMap = new HashMap<>();

    public void setChat(Chat chat) {
        this.chat = chat;
    }

    public Server(EditSession session, int port, int bufferSize) {
        logger.log(System.Logger.Level.DEBUG, port);
        logger.log(System.Logger.Level.DEBUG, bufferSize);
        editSession = session;
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

    public Server(EditSession session, int port) {
        this(session, port, 256);
    }

    public Server(EditSession session) {
        this(session, 8080);
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
                            registerNewConn();
                        } else if (key.isReadable()) {
                            readConn(key);
                        }
                    }
                }
            } catch (IOException _e) {
                continue;
            }
        }
    }

    private void readConn(SelectionKey key) throws IOException {
        SocketChannel client = (SocketChannel) key.channel();
        Conn conn = (Conn) connHashMap.get(client);
        if (client.read(buffer) < 0) {
            key.cancel();
            client.close();
        } else {
            buffer.flip();

            String request = CodeUtil.stringFromBuffer(buffer);
            Cmd cmd = new Cmd();
            try {
                cmd = cmdParser.parseCmd(request);
            } catch (IOException e) {
                logger.log(System.Logger.Level.ERROR, e.toString());
            }
            logger.log(System.Logger.Level.DEBUG, cmd.toString());
            if (cmd.eType == CmdType.MESSAGE && chat != null) {
                chat.sendMessage(cmd.user, cmd.content);
            } else {
                editSession.ExecuteCmd(cmd);
            }

            conn.writeToChan(CodeUtil.bufferFromString(request));

            buffer.clear();
        }
    }

    private void registerNewConn() throws IOException {
        SocketChannel client = server.accept();
        client.configureBlocking(false);
        client.register(
                selector,
                SelectionKey.OP_READ,
                client.socket().getPort()
        );
        connHashMap.put(client, new Conn(client));
    }
}
