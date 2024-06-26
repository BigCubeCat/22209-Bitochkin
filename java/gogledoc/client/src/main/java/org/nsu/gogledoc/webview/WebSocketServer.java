package org.nsu.gogledoc.webview;

import io.javalin.Javalin;
import io.javalin.websocket.WsCloseContext;
import io.javalin.websocket.WsConnectContext;
import io.javalin.websocket.WsContext;
import io.javalin.websocket.WsMessageContext;
import org.nsu.gogledoc.Controller.Data;
import org.nsu.gogledoc.Logger.ClientLoggerFinder;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class WebSocketServer implements Runnable {
    private final System.Logger logger = ClientLoggerFinder.getLogger("ws", this.getClass().getModule());

    private static final Map<WsContext, String> userUsernameMap = new ConcurrentHashMap<>();
    private static int nextUserNumber = 1; // Assign to username for next connecting user

    private final int port;
    Data clientToServer;
    Data serverToClient;

    public WebSocketServer(Data data1, Data data2, int port) {
        this.port = port;
        serverToClient = data1;
        clientToServer = data2;
    }

    private void onUserConnect(WsConnectContext ctx) {
        String username = "u" + nextUserNumber++;
        userUsernameMap.put(ctx, username);
    }

    private void onUserClose(WsCloseContext ctx) {
        userUsernameMap.remove(ctx);
    }

    private void onMessage(WsMessageContext ctx) {
        String request = ctx.message();
        clientToServer.produce(request);
        String response = serverToClient.consume();
        broadcastMessage(response);
    }

    @Override
    public void run() {
        Javalin app = Javalin.create(config -> {
            config.router.mount(router -> {
                router.ws("/", ws -> {
                    // Подключение
                    ws.onConnect(this::onUserConnect);
                    // Отключение
                    ws.onClose(this::onUserClose);
                    // Сообщение
                    ws.onMessage(this::onMessage);
                });
            });
        }).start(this.port);
    }

    private static void broadcastMessage(String message) {
        userUsernameMap.keySet().stream().filter(ctx -> ctx.session.isOpen()).forEach(session -> {
            session.send(message);
        });
    }
}
