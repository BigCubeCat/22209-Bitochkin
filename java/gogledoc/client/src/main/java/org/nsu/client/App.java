package org.nsu.client;

import org.nsu.client.Client.SocketClient;

public class App {
    public static void main(String[] args) {
        SocketClient client = new SocketClient(8888);
        client.Run();
    }
}