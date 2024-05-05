package me.bigcubecat.game.AssetManager;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

abstract public class AbstractParser {
    public void ParseFile(String filename) {
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            for (String line; (line = br.readLine()) != null; ) {
                processLine(line);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    abstract void processLine(String line);
}
