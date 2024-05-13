package me.bigcubecat.game.AssetManager;

import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.math.Vector2;
import me.bigcubecat.game.GameObjects.AnimatedObjects.ObjectAnimation;
import me.bigcubecat.game.GameObjects.PhysicObject.BodyConf;

// Singleton - обертка для парсера.

public class GameAssetModel {
    private static GameAssetModel INSTANCE;
    private GameAssetParser parser = new GameAssetParser(
            "assets/config/box2d",
            "assets/config/anime",
            "assets/config/ui",
            "assets/config/map"
    );

    private GameAssetModel() {
    }

    public static GameAssetModel getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new GameAssetModel();
        }
        return INSTANCE;
    }

    public ObjectAnimation getObjectAnimation(String name) {
        return parser.anime().getObjectAnimation(name);
    }

    public BodyConf getPhysicType(String name) {
        return parser.phys().getType(name);
    }

    public Texture getUITexture(String name) {
        return parser.getUiParser().getTexture(name);
    }

    public Vector2 findTower() {
        return parser.getMapParser().towerPosition();
    }

    public Vector2 getObjectMapPosition(String objectName) {
        return parser.getMapParser().getStartPosition(objectName);
    }
}
