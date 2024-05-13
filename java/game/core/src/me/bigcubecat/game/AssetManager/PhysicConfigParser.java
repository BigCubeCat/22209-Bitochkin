package me.bigcubecat.game.AssetManager;

import me.bigcubecat.game.GameObjects.PhysicObject.BodyConf;
import me.bigcubecat.game.Utils.GameLoggerFinder;

import java.lang.reflect.Field;
import java.util.HashMap;

public class PhysicConfigParser extends AbstractParser {
    private final System.Logger logger = GameLoggerFinder.getLogger("box2d_parser", this.getClass().getModule());
    private final HashMap<String, BodyConf> bodyTypes = new HashMap<>();
    private String currentType = "";
    private boolean findCurrentType = false;
    private BodyConf conf = new BodyConf();

    PhysicConfigParser(String name) {
        ParseFile(name);
    }

    public BodyConf getType(String name) {
        if (bodyTypes.containsKey(name)) {
            return bodyTypes.get(name);
        }
        logger.log(System.Logger.Level.ERROR, "body config not found: " + name);
        return null;
    }

    @Override
    void processLine(String line) {
        if (!findCurrentType) {
            currentType = line;
            findCurrentType = true;
        } else if (line.charAt(0) == '}') {
            bodyTypes.put(currentType, new BodyConf(conf));
            findCurrentType = false;
        } else if (line.charAt(0) != '{') {
            try {
                String[] words = line.split(":");
                Field field = conf.getClass().getDeclaredField(words[0]);
                field.setAccessible(true);
                field.set(conf, Float.parseFloat(words[1]));
            } catch (Exception ignored) {
                logger.log(System.Logger.Level.ERROR, "field not found: " + line);
            }
        }
    }
}
