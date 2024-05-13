package me.bigcubecat.game.GameObjects.MoveableObjects;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.World;
import me.bigcubecat.game.AssetManager.GameAssetModel;
import me.bigcubecat.game.GameControl.InputController;
import me.bigcubecat.game.GameObjects.AnimatedObjects.ObjectAnimation;
import me.bigcubecat.game.GameObjects.BattleObjects.Gun;
import me.bigcubecat.game.GameObjects.BattleObjects.HPObject;
import me.bigcubecat.game.GameObjects.PhysicObject.BodyConf;
import me.bigcubecat.game.Utils.Constants;
import me.bigcubecat.game.uiObjects.Aim;

public class Player extends SceneObject {
    GameAssetModel gameAssetModel = GameAssetModel.getInstance();
    HPObject hpObject;
    private final InputController inputController;
    private Aim aim = new Aim();
    private Gun gun;

    public Player() {
        super();
        inputController = InputController.getInstance();
        hpObject = new HPObject("player", Constants.PLAYER_HP);
        tag = "player";
        gun = new Gun(this);
    }

    @Override
    public void Setup(ObjectAnimation anime, BodyConf bodyConfig, World box2dWorld, Vector2 pos) {
        super.Setup(anime, bodyConfig, box2dWorld, pos);
        setHpObject(hpObject);
        hpObject.power = Constants.PLAYER_POWER;
        animatedObject.setCurrentAnimation("right");
    }

    @Override
    public void Setup(MoveableConf conf) {
        super.Setup(conf);
        animatedObject.setCurrentAnimation("right");
    }

    @Override
    public void Update() {
        float deltaTime = Gdx.graphics.getDeltaTime();
        float hpSpeed = deltaTime * hpObject.getHealSpeed();
        if (nearTower()) {
            hpObject.heal(hpSpeed);
        } else {
            hpObject.attack(hpSpeed);
        }
        aim.aimDirection = inputController.getDirection(position);
        if (inputController.shoot) {
            gun.Shoot(false);
        }
        if (inputController.power) {
            gun.Shoot(true);
        }
    }

    private boolean nearTower() {
        Vector2 towerPos = gameAssetModel.findTower();
        float x = (position.x - towerPos.x) / Constants.TILE_SIZE / Constants.SCALE_FACTOR;
        float y = (position.y - towerPos.y) / Constants.TILE_SIZE / Constants.SCALE_FACTOR;
        return (x * x + y * y) < 5 * Constants.TILE_SIZE;
    }

    public float getDirection() {
        return aim.getAngle();
    }

    public void updateViewDir(Vector2 mousePosition) {
        if (!inputController.useController()) {
            aim.aimDirection.x = mousePosition.x - position.x;
            aim.aimDirection.y = mousePosition.y - position.y;
            aim.aimDirection.nor();
        } else {
            aim.aimDirection = inputController.direction.nor();
        }
        aim.update();

        if (Math.abs(aim.aimDirection.x) < Math.abs(aim.aimDirection.y)) {
            if (aim.aimDirection.y < 0) {
                animatedObject.setCurrentAnimation("down");
            } else {
                animatedObject.setCurrentAnimation("up");
            }
        } else {
            if (aim.aimDirection.x < 0) {
                animatedObject.setCurrentAnimation("left");
            } else {
                animatedObject.setCurrentAnimation("right");
            }
        }
        if (!hpObject.isAlive()) {
            animatedObject.setCurrentAnimation("die");
        }
    }

    public void render(SpriteBatch batch, Vector2 cornerPosition) {
        super.render(batch, cornerPosition);
        aim.setPosition(position, cornerPosition);
        aim.render(batch);
        gun.renderBullets(batch, cornerPosition);
    }

    public boolean isAlive() {
        return hpObject.isAlive();
    }

    public float livePercent() {
        return hpObject.hpPercent();
    }

    @Override
    public void Destroy() {
        super.Destroy();
        gun.Destroy();
    }
}
