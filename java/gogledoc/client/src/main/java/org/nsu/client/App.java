package org.nsu.client;

import org.nsu.client.webview.WebSocketServer;

public class App {
    public static void main(String[] args) {
        /*
        SocketClient client = new SocketClient(8888);
        client.Run();
         */
        WebSocketServer server = new WebSocketServer(8080);
        server.RunServer();
    }
}