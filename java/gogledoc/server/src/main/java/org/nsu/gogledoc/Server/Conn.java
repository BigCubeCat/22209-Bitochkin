package org.nsu.gogledoc.Server;

import org.nsu.gogledoc.FileWorker.EditSession;
import org.nsu.gogledoc.Utils.CodeUtil;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;

public class Conn {
    private EditSession session;
    private final SocketChannel channel;

    public Conn(SocketChannel chan) {
        channel = chan;
    }

    public void writeToChan(ByteBuffer buffer) {
        try {
            channel.write(buffer);
            channel.write(CodeUtil.bufferFromString(""));
        } catch (IOException ignored) {
        }
    }
}
