package me.bigcubecat.game.GameObjects.MoveableObjects;


import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.World;
import me.bigcubecat.game.AI.ChaoticAI;
import me.bigcubecat.game.GameObjects.AnimatedObjects.ObjectAnimation;
import me.bigcubecat.game.GameObjects.BattleObjects.HPObject;
import me.bigcubecat.game.GameObjects.PhysicObject.BodyConf;
import me.bigcubecat.game.Utils.Constants;

public class Enemy extends SceneObject {
    HPObject hpObject;
    ChaoticAI ai = new ChaoticAI();
    Vector2 direction;

    public Enemy() {
        super();
        hpObject = new HPObject("enemy", Constants.ENEMY_HP);
        hpObject.power = Constants.ENEMY_POWER;
    }

    @Override
    public void Update() {
        if (!hpObject.isAlive()) {
            die();
        }
        animatedObject.setBlend(hpObject.blendPercent());
        direction = ai.getDirection(position);
        Move(direction.x, direction.y);
    }

    @Override
    public void Setup(ObjectAnimation anime, BodyConf bodyConfig, World box2dWorld, Vector2 pos) {
        super.Setup(anime, bodyConfig, box2dWorld, pos);
        setHpObject(hpObject);
        hpObject.power = Constants.ENEMY_POWER;
        animatedObject.setCurrentAnimation("idle");
    }

    @Override
    public void Setup(MoveableConf conf) {
        super.Setup(conf);
        setHpObject(hpObject);
        hpObject.power = Constants.ENEMY_POWER;
        animatedObject.setCurrentAnimation("idle");
    }

    private void die() {
        physicObject.Destroy();
        animatedObject.setCurrentAnimation("die", false);
        hpObject.increaseCounter();
        if (hpObject.destroy()) {
            Destroy();
        }
    }
}
