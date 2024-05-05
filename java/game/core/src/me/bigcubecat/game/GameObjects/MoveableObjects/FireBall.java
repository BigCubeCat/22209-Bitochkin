package me.bigcubecat.game.GameObjects.MoveableObjects;

import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.World;
import me.bigcubecat.game.AssetManager.GameAssetModel;
import me.bigcubecat.game.GameObjects.BattleObjects.HPObject;
import me.bigcubecat.game.Utils.Constants;

public class FireBall extends BulletObject {
    public FireBall(World world, Vector2 position, Vector2 direction, float power) {
        super();
        this.direction = direction;
        hpObject = new HPObject(Constants.FIREBALL_NAME, Constants.MINIMUM_ATTACK); // Minimum HP
        hpObject.power = power;
        GameAssetModel assetModel = GameAssetModel.getInstance();
        Setup(
                assetModel.getObjectAnimation(Constants.FIREBALL_NAME),
                assetModel.getPhysicType(Constants.FIREBALL_NAME),
                world, position
        );
    }
}
