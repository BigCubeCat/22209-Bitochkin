package me.bigcubecat.game.GameObjects.MoveableObjects;

import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.World;
import me.bigcubecat.game.AssetManager.GameAssetModel;
import me.bigcubecat.game.GameObjects.BattleObjects.HPObject;
import me.bigcubecat.game.Utils.Constants;

public class PowerFire extends BulletObject {

    public PowerFire(World world, Vector2 position, Vector2 direction) {
        super();
        this.direction = direction;
        hpObject = new HPObject(Constants.POWER_NAME, Constants.POWER_HP);
        hpObject.power = Constants.POWER_POWER;
        GameAssetModel assetModel = GameAssetModel.getInstance();
        Setup(
                assetModel.getObjectAnimation(Constants.POWER_NAME),
                assetModel.getPhysicType(Constants.POWER_NAME),
                world, position
        );
        physicObject.setTriggered();
    }

}
