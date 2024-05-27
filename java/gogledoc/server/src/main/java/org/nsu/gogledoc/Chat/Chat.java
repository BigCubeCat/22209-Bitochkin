package org.nsu.gogledoc.Chat;

import org.nsu.gogledoc.FileWorker.EditSession;
import org.nsu.gogledoc.FileWorker.UserFile;

import java.io.IOException;

public class Chat extends EditSession {
    public Chat(UserFile db) {
        super(db);
    }

    public void sendMessage(String username, String message) throws IOException {

    }
}
