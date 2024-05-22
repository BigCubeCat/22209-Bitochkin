package org.nsu.client;

import org.nsu.client.Config.Config;
import org.nsu.client.Controller.MessageController;

public class App {
    public static void main(String[] args) {
        Config config = new Config();
        config.webSocketPort = 8080;
        config.serverPort = 8888;

        MessageController controller = new MessageController(config);
        controller.startThreads();
    }
}