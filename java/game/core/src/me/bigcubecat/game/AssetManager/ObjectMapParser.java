package me.bigcubecat.game.AssetManager;

import com.badlogic.gdx.math.Vector2;

import java.util.HashMap;

public class ObjectMapParser extends AbstractParser {
    private HashMap<String, Vector2> objects = new HashMap<>();

    ObjectMapParser(String name) {
        ParseFile(name);
    }

    @Override
    void processLine(String line) {
        String[] words = line.split(" ");
        objects.put(words[0], new Vector2(Float.parseFloat(words[1]), Float.parseFloat(words[2])));
        System.out.println(objects.get(words[0]));
    }

    public Vector2 getStartPosition(String name) {
        if (objects.containsKey(name)) {
            return objects.get(name);
        }
        return objects.get(name);
    }

    public Vector2 towerPosition() {
        return objects.get("tower");
    }
}
