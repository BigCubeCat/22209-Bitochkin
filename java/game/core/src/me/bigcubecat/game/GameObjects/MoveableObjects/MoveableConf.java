package me.bigcubecat.game.GameObjects.MoveableObjects;

import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.World;
import me.bigcubecat.game.GameObjects.AnimatedObjects.ObjectAnimation;
import me.bigcubecat.game.GameObjects.PhysicObject.BodyConf;
import me.bigcubecat.game.AssetManager.GameAssetModel;

public class MoveableConf {
    public ObjectAnimation objectAnimation;
    public BodyConf bodyConf;
    public World world;
    public Vector2 position;

    public MoveableConf(String objectName, World box2dWorld, Vector2 pos) {
        GameAssetModel model = GameAssetModel.getInstance();
        objectAnimation = model.getObjectAnimation(objectName);
        bodyConf = model.getPhysicType(objectName);
        world = box2dWorld;
        position = pos;
    }

    public MoveableConf() {
    }
}
