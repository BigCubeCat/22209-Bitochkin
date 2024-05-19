package org.nsu.gogledoc;

import org.nsu.gogledoc.Chat.Chat;
import org.nsu.gogledoc.FileWorker.EditSession;
import org.nsu.gogledoc.FileWorker.UserFile;
import org.nsu.gogledoc.Server.Server;

public class App {
    public static void main(String[] args) {
        UserFile file = new UserFile("data.txt");
        UserFile chatFile = new UserFile("chat.txt");
        EditSession session = new EditSession(file);
        Chat chat = new Chat(chatFile);
        Server server = new Server(session, 8888);
        server.setChat(chat);
        server.RunServer();
    }
}
