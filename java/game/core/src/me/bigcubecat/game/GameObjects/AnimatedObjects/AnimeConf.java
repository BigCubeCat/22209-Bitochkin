package me.bigcubecat.game.GameObjects.AnimatedObjects;

public class AnimeConf {
    public String title;
    public String filepath;
    public float frameDuration;
    public int countRows;
    public int countColumns;
    public AnimeConf(String [] line) {
        title = line[1];
        filepath = line[2];
        frameDuration = Float.parseFloat(line[3]);
        countRows = Integer.parseInt(line[4]);
        countColumns = Integer.parseInt(line[5]);
    }
}
