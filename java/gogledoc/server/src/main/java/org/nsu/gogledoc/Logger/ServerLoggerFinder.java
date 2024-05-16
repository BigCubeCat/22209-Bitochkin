package org.nsu.gogledoc.Logger;

public class ServerLoggerFinder {
    public static System.Logger getLogger(String name, Module module) {
        return new ServerLogger(name);
    }
}
