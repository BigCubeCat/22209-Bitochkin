package org.nsu.gogledoc.Controller;

import org.nsu.gogledoc.Client.SocketClient;
import org.nsu.gogledoc.Config.Config;
import org.nsu.gogledoc.webview.WebSocketServer;

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
