package me.bigcubecat.game.Utils;

public class GameLoggerFinder {
    public static System.Logger getLogger(String name, Module module) {
        return new GameLogger(name);
    }
}

