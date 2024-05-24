package org.nsu.client;

import org.nsu.client.Config.Config;
import org.nsu.client.Controller.MessageController;

public class App {
    public static void main(String[] args) {
        Config config = new Config(true);

        MessageController controller = new MessageController(config);
        controller.startThreads();
    }
}