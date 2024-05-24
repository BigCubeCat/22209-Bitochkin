package org.nsu.gogledoc.Config;

public class Config {
    public int webSocketPort;
    public int serverPort;
    public String serverHost = "127.0.0.1";

    public Config(boolean useEnv) {
        if (useEnv) {
            serverHost = System.getenv("SERVER_HOST");
            serverPort = Integer.parseInt(System.getenv("SERVER_PORT"));
            webSocketPort = Integer.parseInt(System.getenv("WS_PORT"));
        }
    }
}
