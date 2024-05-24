package org.nsu.client.Controller;

import org.nsu.client.Client.SocketClient;
import org.nsu.client.Config.Config;
import org.nsu.client.webview.WebSocketServer;

public class MessageController {
    Thread clientThread;
    Thread wsThread;

    public MessageController(Config conf) {
        Data clientToServer = new Data();
        Data serverToClient = new Data();

        clientThread = new Thread(new SocketClient(serverToClient, clientToServer, conf.serverHost, conf.serverPort));
        wsThread = new Thread(new WebSocketServer(serverToClient, clientToServer, conf.webSocketPort));
    }

    public void startThreads() {
        clientThread.start();
        wsThread.start();
    }
}
