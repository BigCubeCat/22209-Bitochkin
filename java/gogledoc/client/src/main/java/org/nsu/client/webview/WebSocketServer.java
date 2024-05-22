package org.nsu.client.webview;

import io.javalin.Javalin;
import io.javalin.websocket.WsCloseContext;
import io.javalin.websocket.WsConnectContext;
import io.javalin.websocket.WsContext;
import io.javalin.websocket.WsMessageContext;
import org.nsu.client.Controller.Data;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class WebSocketServer implements Runnable {
    private static final Map<WsContext, String> userUsernameMap = new ConcurrentHashMap<>();
    private static int nextUserNumber = 1; // Assign to username for next connecting user

    private final int port;
    Data data;

    public WebSocketServer(Data data, int port) {
        this.port = port;
        this.data = data;
    }

    private void onUserConnect(WsConnectContext ctx) {
        String username = "u" + nextUserNumber++;
        userUsernameMap.put(ctx, username);
        broadcastMessage("server", "user joined the chat");
    }

    private void onUserClose(WsCloseContext ctx) {
        String username = userUsernameMap.get(ctx);
        userUsernameMap.remove(ctx);
        broadcastMessage("server", (username + " left the chat"));
    }

    private void onMessage(WsMessageContext ctx) {
        // TODO: отправка на TCP-сервер
        broadcastMessage(userUsernameMap.get(ctx), ctx.message());
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

    // Sends a message from one user to all users, along with a list of current usernames
    private static void broadcastMessage(String sender, String message) {
        userUsernameMap.keySet().stream().filter(ctx -> ctx.session.isOpen()).forEach(session -> {
            session.send(
                    Map.of(
                            "message", createMessage(message),
                            "users", userUsernameMap.values()
                    )
            );
        });
    }

    private static String createMessage(String message) {
        return message;
    }
}
