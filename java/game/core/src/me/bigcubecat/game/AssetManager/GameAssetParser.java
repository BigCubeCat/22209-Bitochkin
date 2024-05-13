package me.bigcubecat.game.AssetManager;

public class GameAssetParser {
    private PhysicConfigParser physicParser;
    private AnimatedConfigParser animeParser;
    private UIParser uiParser;

    private ObjectMapParser mapParser;

    public GameAssetParser(String physicFileName, String animeFileName, String uiFileName, String mapFileName) {
        physicParser = new PhysicConfigParser(physicFileName);
        animeParser = new AnimatedConfigParser(animeFileName);
        uiParser = new UIParser(uiFileName);
        mapParser = new ObjectMapParser(mapFileName);
    }

    public AnimatedConfigParser anime() {
        return animeParser;
    }

    public PhysicConfigParser phys() {
        return physicParser;
    }

    public UIParser getUiParser() {
        return uiParser;
    }

    public ObjectMapParser getMapParser() {
        return mapParser;
    }
}
