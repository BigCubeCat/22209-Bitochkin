package me.bigcubecat.game.AssetManager;

import com.badlogic.gdx.graphics.Texture;

import java.util.HashMap;

public class UIParser extends AbstractParser{
    HashMap<String, Texture> uiTextures = new HashMap<>();
    public UIParser(String name) {
        ParseFile(name);
    }
    @Override
    void processLine(String line) {
        String[] words = line.split(" ");
        uiTextures.put(words[0], new Texture(words[1]));
    }

    public Texture getTexture(String name) {
        return uiTextures.get(name);
    }
}
