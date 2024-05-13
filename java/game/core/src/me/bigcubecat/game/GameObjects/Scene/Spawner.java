package me.bigcubecat.game.GameObjects.Scene;

import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.World;
import me.bigcubecat.game.GameObjects.MoveableObjects.Enemy;
import me.bigcubecat.game.GameObjects.MoveableObjects.MoveableConf;
import me.bigcubecat.game.GameObjects.MoveableObjects.MoveableFactory;
import me.bigcubecat.game.Utils.Constants;
import me.bigcubecat.game.Utils.GameLoggerFinder;
import me.bigcubecat.game.Utils.ProbAlgos;

import java.util.ArrayList;

public class Spawner {
    private ArrayList<Enemy> enemies = new ArrayList<>();
    MoveableFactory enemyFactory;
    World box2dWorld;
    String name;
    Vector2 position;
    float time = 0;
    float delayCounter = Constants.TIME_DELAY;

    public Spawner(World world, MoveableFactory factory, String objectName, Vector2 pos) {
        name = objectName;
        box2dWorld = world;
        enemyFactory = factory;
        position = pos;
    }

    public void Update(float deltaTime, Vector2 worldPosition) {
        time += deltaTime;
        if (ProbAlgos.ExpSpawn(time)) {
            delayCounter -= Constants.ACCELERATION;
            if (delayCounter < Constants.MINIMUM_DELAY) {
                delayCounter = Constants.MINIMUM_DELAY;
            }
            Spawn();
            time = 0;
        }
        Enemy en;
        for (int i = enemies.size() - 1; i >= 0; --i) {
            en = enemies.get(i);
            enemies.get(i).Update();
            if (!en.isAlive()) {
                System.out.println("die");
                enemies.remove(i);
            }
        }

    }

    public void Spawn() {
        try {
            enemies.add((Enemy) enemyFactory.createObject(name, new MoveableConf(name, box2dWorld, position)));
        } catch (Exception ignored) {
        }
    }

    public void render(SpriteBatch batch, Vector2 corner) {
        for (Enemy e : enemies) {
            e.render(batch, corner);
        }
    }

    public void Destroy() {
        for (Enemy e : enemies) {
            e.Destroy();
        }
    }
}
