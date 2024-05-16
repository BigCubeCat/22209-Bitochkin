package org.nsu.gogledoc.Server;

import org.nsu.gogledoc.FileWorker.EditSession;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;

public class Conn {
    private EditSession session;
    private SocketChannel channel;

    public Conn(SocketChannel chan) {
        channel = chan;
//        session = new EditSession();
    }

    public void writeToChan(ByteBuffer buffer) {
        try {
            channel.write(buffer);
        } catch (IOException ignored) {
        }
    }
}
