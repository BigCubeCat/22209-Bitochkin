package org.nsu.gogledoc.Server;

import org.nsu.gogledoc.FileWorker.EditSession;

import java.nio.channels.SocketChannel;

public class Conn {
    private EditSession session;
    private SocketChannel channel;

    public Conn(SocketChannel chan) {
        channel = chan;
        session = new EditSession();
    }

    public void readFromChannel() {
        // TODO
    }
}
