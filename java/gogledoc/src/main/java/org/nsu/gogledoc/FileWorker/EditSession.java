package org.nsu.gogledoc.FileWorker;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.file.StandardOpenOption;
import java.util.EnumSet;
import java.util.Queue;

public class EditSession {
    private UserFile userFile;
    private Queue<String> users;
    private FileChannel fileChannel;
    private boolean synced = false;

    public EditSession() {
        try {
            fileChannel = FileChannel.open(
                    userFile.getFilePath(),
                    EnumSet.of(StandardOpenOption.CREATE,
                            StandardOpenOption.TRUNCATE_EXISTING,
                            StandardOpenOption.WRITE)
            );
        } catch (IOException ioException) {
            // TODO: logger
        }
    }

    public void write() throws IOException {
        ServerSocketChannel serverSocket = null;
        SocketChannel client = null;
        serverSocket = ServerSocketChannel.open();
        serverSocket.socket().bind(new InetSocketAddress(9000));
        client = serverSocket.accept();
        System.out.println("Connection Set:  " + client.getRemoteAddress());
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        while (client.read(buffer) > 0) {
            buffer.flip();
            fileChannel.write(buffer);
            buffer.clear();
        }
        fileChannel.close();
        System.out.println("File Received");
        client.close();
    }
}
