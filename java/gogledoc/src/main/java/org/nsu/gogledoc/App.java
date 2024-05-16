package org.nsu.gogledoc;

import org.nsu.gogledoc.FileWorker.EditSession;
import org.nsu.gogledoc.FileWorker.UserFile;
import org.nsu.gogledoc.Server.Server;

public class App {
    public static void main(String[] args) {
        UserFile file = new UserFile("data.txt");
        // по сути чат это тот же файл, в который можно только писать
        UserFile chat = new UserFile("chat.txt");

        EditSession session = new EditSession(file);
        Server server = new Server(session);
        server.RunServer();
    }
}
