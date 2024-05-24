package org.nsu.gogledoc;

import org.nsu.gogledoc.Config.Config;
import org.nsu.gogledoc.Controller.MessageController;

public class App {
    public static void main(String[] args) {
        Config config = new Config(true);

        MessageController controller = new MessageController(config);
        controller.startThreads();
    }
}