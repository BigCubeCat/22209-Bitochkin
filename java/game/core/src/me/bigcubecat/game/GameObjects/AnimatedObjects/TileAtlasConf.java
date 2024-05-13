package me.bigcubecat.game.GameObjects.AnimatedObjects;

import com.badlogic.gdx.graphics.Texture;

public class TileAtlasConf {
    public String name;
    public Texture tileAtlas;
    public float frameDuration;
    public int countRows;
    public int countCols;
    public int startRow = 0;
    public int startCol = 0;

    TileAtlasConf(
            String tileName, Texture atlas, float duration,
            int rows, int cols,
            int startR, int startColumn) {
        name = tileName;
        tileAtlas = atlas;
        frameDuration = duration;
        countRows = rows;
        countCols = cols;
        startRow = startR;
        startCol = startColumn;
    }
}
