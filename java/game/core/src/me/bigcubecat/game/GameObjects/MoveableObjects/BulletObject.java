package me.bigcubecat.game.GameObjects.MoveableObjects;

import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.World;
import me.bigcubecat.game.GameObjects.AnimatedObjects.ObjectAnimation;
import me.bigcubecat.game.GameObjects.BattleObjects.HPObject;
import me.bigcubecat.game.GameObjects.PhysicObject.BodyConf;

public class BulletObject extends SceneObject {
    HPObject hpObject;
    Vector2 direction;

    @Override
    public void Update() {
        Move(direction.x, direction.y);
        if (!hpObject.isAlive()) {
            Destroy();
        }
    }

    @Override
    public void Setup(ObjectAnimation anime, BodyConf bodyConfig, World box2dWorld, Vector2 pos) {
        super.Setup(anime, bodyConfig, box2dWorld, pos);
        setHpObject(hpObject);
        animatedObject.setCurrentAnimation("idle");
    }

    @Override
    public void Setup(MoveableConf conf) {
        super.Setup(conf);
        setHpObject(hpObject);
        animatedObject.setCurrentAnimation("idle");
    }
}
