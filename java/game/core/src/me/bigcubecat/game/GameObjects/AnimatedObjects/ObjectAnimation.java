package me.bigcubecat.game.GameObjects.AnimatedObjects;

import com.badlogic.gdx.graphics.Texture;

import java.util.HashMap;

public class ObjectAnimation {
    public String title;
    public HashMap<String, TileAtlasConf> states = new HashMap<>();

    public ObjectAnimation(String name) {
        title = name;
    }

    public void addTile(
            String name, Texture tileAtlas, float frameDuration,
            int countRows, int countCols,
            int startRow, int startCol
    ) {
        states.put(name, new TileAtlasConf(name, tileAtlas, frameDuration, countRows, countCols, startRow, startCol));
    }
}
