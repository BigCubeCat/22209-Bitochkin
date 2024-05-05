package me.bigcubecat.game.GameControl;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.*;
import me.bigcubecat.game.GameObjects.BattleObjects.HPObject;
import me.bigcubecat.game.GameView.GameCamera;
import me.bigcubecat.game.Utils.Constants;

public class Box2DController {
    private static Box2DController INSTANCE;
    boolean debug = false;

    private World world;
    Box2DDebugRenderer debugRenderer = new Box2DDebugRenderer();

    public static Box2DController getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new Box2DController(Constants.DEBUG);
        }
        return INSTANCE;
    }

    private Box2DController(boolean debugging) {
        debug = debugging;
        createWorld();
    }

    private void doPhysicsStep(float deltaTime) {
        world.step(
                Constants.BOX2D_TIME_STEP,
                Constants.BOX2D_VELOCITY_INTERATIONS,
                Constants.BOX2D_POSITION_ITERATIONS
        );
    }

    public void createWorld() {
        world = new World(new Vector2(0, 0), true);

        world.setContactListener(new ContactListener() {
            @Override
            public void beginContact(Contact contact) {
                try {
                    Body bdyA = contact.getFixtureA().getBody();
                    Body bdyB = contact.getFixtureB().getBody();
                    HPObject bodyA = (HPObject) bdyA.getUserData();
                    HPObject bodyB = (HPObject) bdyB.getUserData();
                    if (bodyA.Tag == Constants.POWER_NAME) {
                        bodyA.attack(Constants.TOWER_HP);
                    }
                    if (bodyB.Tag == Constants.POWER_NAME) {
                        bodyB.attack(Constants.TOWER_HP);
                    }
                    if (bodyA.Tag == Constants.FIREBALL_NAME) {
                        bodyA.attack(Constants.FIREBALL_POWER);
                    }
                    if (bodyB.Tag == Constants.FIREBALL_NAME) {
                        bodyB.attack(Constants.FIREBALL_POWER);
                    }
                    if (bodyA.Tag.charAt(0) != bodyB.Tag.charAt(0)) {
                        bodyA.attack(bodyB.power);
                        bodyB.attack(bodyA.power);
                    } else {
                        bodyA.heal(bodyB.power);
                        bodyB.heal(bodyA.power);
                    }
                } catch (Exception ignore) {
                }
            }

            @Override
            public void endContact(Contact contact) {
            }

            @Override
            public void preSolve(Contact contact, Manifold oldManifold) {
            }

            @Override
            public void postSolve(Contact contact, ContactImpulse impulse) {
            }
        });
    }

    public void Update(GameCamera camera) {
        doPhysicsStep(Gdx.graphics.getDeltaTime());
        if (debug) {
            debugRenderer.render(world, camera.combined);
        }
    }

    public World getWorld() {
        return world;
    }
}
