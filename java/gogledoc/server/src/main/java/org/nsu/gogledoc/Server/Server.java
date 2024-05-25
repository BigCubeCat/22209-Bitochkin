package org.nsu.gogledoc.Server;

import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.node.ObjectNode;
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
import java.nio.channels.*;
import java.util.*;

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
                        try {
                            SelectionKey key = iterator.next();
                            iterator.remove();
                            if (key.isAcceptable()) {
                                logger.log(System.Logger.Level.DEBUG, "key is acceptable");
                                registerNewConn();
                            } else {
                                if (key.isReadable()) {
                                    logger.log(System.Logger.Level.DEBUG, "key is readable");
                                    readConn(key);
                                    logger.log(System.Logger.Level.DEBUG, "key has been read");
                                }
                                if (key.isWritable()) {
                                    logger.log(System.Logger.Level.DEBUG, "key is writable");
                                    writeConn(key);
                                    logger.log(System.Logger.Level.DEBUG, "key has been written");
                                }
                            }
                        } catch (CancelledKeyException e) {
                            logger.log(System.Logger.Level.WARNING, e);
                        }
                    }
                }
            } catch (IOException _e) {
                continue;
            }
        }
    }

    private void writeConn(SelectionKey key) throws IOException {
        logger.log(System.Logger.Level.DEBUG, "write");
        SocketChannel client = (SocketChannel) key.channel();
        Conn conn = (Conn) connHashMap.get(client);
        conn.writeToChan(CodeUtil.bufferFromString(""));
        key.interestOps(SelectionKey.OP_READ);
    }

    private void readConn(SelectionKey key) throws IOException {
        logger.log(System.Logger.Level.DEBUG, "read conn");
        SocketChannel client = (SocketChannel) key.channel();
        Conn conn = (Conn) connHashMap.get(client);
        if (client.read(buffer) < 0) {
            logger.log(System.Logger.Level.DEBUG, "no msg");
            key.cancel();
            client.close();
        } else {
            buffer.flip();
            String request = CodeUtil.stringFromBuffer(buffer);
            Cmd cmd = cmdParser.parseCmd(request);
            logger.log(System.Logger.Level.DEBUG, "parse cmd from client");
            var response = editSession.ExecuteCmd(cmd);
            ObjectMapper mapper = new ObjectMapper();
            JsonNode node = mapper.valueToTree(response);
            String nodeString = node.toString();
            System.out.println(nodeString);
            conn.writeToChan(CodeUtil.bufferFromString(nodeString));
            logger.log(System.Logger.Level.DEBUG, "written to connection");
            buffer.clear();
        }
        key.interestOps(SelectionKey.OP_WRITE);
    }

    private void registerNewConn() throws IOException {
        logger.log(System.Logger.Level.INFO, "new connection request");
        SocketChannel client = server.accept();
        logger.log(System.Logger.Level.INFO, "new client accepted");
        client.configureBlocking(false);
        client.register(
                selector,
                SelectionKey.OP_READ,
                client.socket().getPort()
        );
        connHashMap.put(client, new Conn(client));
    }
}
