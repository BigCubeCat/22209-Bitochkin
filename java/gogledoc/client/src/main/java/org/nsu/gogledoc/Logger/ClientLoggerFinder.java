package org.nsu.gogledoc.Logger;

public class ClientLoggerFinder {
    public static System.Logger getLogger(String name, Module module) {
        return new ClientLogger(name);
    }
}
