package org.nsu.gogledoc;

import org.nsu.gogledoc.FileWorker.EditSession;
import org.nsu.gogledoc.FileWorker.UserFile;
import org.nsu.gogledoc.Server.Server;

public class App {
    public static void main(String[] args) {
        UserFile file = new UserFile("data.txt");
        EditSession session = new EditSession(file);
        Server server = new Server(session, 9999);
        server.RunServer();
    }
}
