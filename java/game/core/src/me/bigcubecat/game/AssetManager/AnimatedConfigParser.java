package me.bigcubecat.game.AssetManager;

import com.badlogic.gdx.graphics.Texture;
import me.bigcubecat.game.GameObjects.AnimatedObjects.AnimeConf;
import me.bigcubecat.game.GameObjects.AnimatedObjects.ObjectAnimation;

import java.util.HashMap;

public class AnimatedConfigParser extends AbstractParser {
    private final HashMap<String, HashMap<String, AnimeConf>> animatedData = new HashMap<>();
    private String currentAnimation = "";

    AnimatedConfigParser(String name) {
        ParseFile(name);
    }

    private void addAnimation(String current, String[] line) {
        try {
            if (!animatedData.containsKey(current)) {
                animatedData.put(current, new HashMap<String, AnimeConf>());
            }
            animatedData.get(current).put(line[1], new AnimeConf(line));
        } catch (Exception ignored) {
        }
    }

    private AnimeConf getAnimeConf(String objectName, String animationName) {
        return animatedData.get(objectName).get(animationName);
    }

    private String[] getAnime(String objectName) {
        if (animatedData.containsKey(objectName)) {
            return animatedData.get(objectName).keySet().toArray(new String[0]);
        }
        return new String[0];
    }

    public ObjectAnimation getObjectAnimation(String objectName) {
        String[] animationModes = getAnime(objectName);
        ObjectAnimation animation = new ObjectAnimation(objectName);
        for (String animeMode : animationModes) {
            AnimeConf conf = getAnimeConf(objectName, animeMode);
            Texture texture = new Texture(conf.filepath);
            animation.addTile(
                    conf.title, texture,
                    conf.frameDuration,
                    conf.countRows, conf.countColumns, 0, 0
            );
        }
        return animation;
    }

    @Override
    void processLine(String line) {
        String[] words = line.split(" ");
        if (line.charAt(0) == '@') {
            addAnimation(currentAnimation, words);
        } else {
            currentAnimation = words[0];
        }
    }
}
