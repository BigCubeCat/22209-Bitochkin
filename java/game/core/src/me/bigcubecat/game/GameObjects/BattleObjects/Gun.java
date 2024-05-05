package me.bigcubecat.game.GameObjects.BattleObjects;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;
import me.bigcubecat.game.GameControl.Box2DController;
import me.bigcubecat.game.GameObjects.MoveableObjects.BulletObject;
import me.bigcubecat.game.GameObjects.MoveableObjects.FireBall;
import me.bigcubecat.game.GameObjects.MoveableObjects.Player;
import me.bigcubecat.game.GameObjects.MoveableObjects.PowerFire;
import me.bigcubecat.game.Utils.Constants;

import java.util.ArrayList;

public class Gun {
    private Player player;
    private float shootCooldownTimer = 0;
    private float powerCooldownTimer = 0;

    private final float cooldown = Constants.COOLDOWN;
    private final float powerCooldown = Constants.POWER_COOLDOWN;

    ArrayList<BulletObject> balls = new ArrayList<>();

    public Gun(Player player) {
        this.player = player;
    }

    public void Shoot(boolean ultra) {
        if (ultra) {
            powerCooldownTimer -= Gdx.graphics.getDeltaTime();
            if (powerCooldownTimer <= 0) {
                powerCooldownTimer = powerCooldown;
                power();
            }
        } else {
            shootCooldownTimer -= Gdx.graphics.getDeltaTime();
            if (shootCooldownTimer <= 0) {
                shootCooldownTimer = cooldown;
                fire();
            }
        }
    }

    private FireBall generateBullet() {
        Vector2 position = new Vector2(Constants.FIREBALL_DISTANCE, 0);
        Vector2 pos = player.getPosition();
        float deg = player.getDirection();
        position.rotateDeg(deg);
        position.add(pos);

        Vector2 dir = new Vector2(1, 0);
        dir.rotateDeg(deg);

        return new FireBall(Box2DController.getInstance().getWorld(), position, dir, Constants.PLAYER_POWER);
    }

    private PowerFire generateSuperBall() {
        Vector2 position = new Vector2(Constants.FIREBALL_DISTANCE * 5, 0);
        Vector2 pos = player.getPosition();
        float deg = player.getDirection();
        position.rotateDeg(deg);
        position.add(pos);

        Vector2 dir = new Vector2(1, 0);
        dir.rotateDeg(deg);

        return new PowerFire(Box2DController.getInstance().getWorld(), position, dir);
    }

    private void fire() {
        balls.add(generateBullet());
    }

    private void power() {
        balls.add(generateSuperBall());
    }


    public void renderBullets(SpriteBatch batch, Vector2 corner) {
        for (int i = balls.size() - 1; i >= 0; --i) {
            if (!balls.get(i).isAlive()) {
                balls.remove(i);
                continue;
            }
            balls.get(i).Update();
            balls.get(i).render(batch, corner);
        }
    }

    public void Destroy() {
        for (BulletObject ball : balls) {
            ball.Destroy();
        }
        balls = new ArrayList<>();
    }
}
