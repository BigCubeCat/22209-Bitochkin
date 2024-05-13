package me.bigcubecat.game.GameObjects.PhysicObject;

import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.*;

public class PhysicObject {
    Body body;
    private float speed;
    boolean destroyed = false;

    public PhysicObject(World world, Vector2 position, BodyConf conf) {
        speed = conf.speed;

        body = world.createBody(createBodyDef(position));
        body.setBullet(true);
        CircleShape circle = new CircleShape();
        circle.setRadius(conf.radius);

        FixtureDef fixtureDef = new FixtureDef();
        fixtureDef.shape = circle;
        fixtureDef.density = conf.density;
        fixtureDef.friction = conf.friction;
        fixtureDef.restitution = conf.restitution;

        body.createFixture(fixtureDef);
        circle.dispose();
    }

    private BodyDef createBodyDef(Vector2 position) {
        BodyDef bodyDef = new BodyDef();
        bodyDef.type = BodyDef.BodyType.DynamicBody;
        bodyDef.position.set(position.x, position.y);
        return bodyDef;
    }

    public void move(float x, float y) {
        if (x != 0 || y != 0) {
            Vector2 pos = body.getPosition();
            body.setTransform(new Vector2(pos.x + x * speed, pos.y + y * speed), 0);
        }
    }

    public Vector2 getPosition() {
        return body.getPosition();
    }

    public void setSpeed(float sp) {
        speed = sp;
    }

    public void setObject(Object obj) {
        body.setUserData(obj);
    }

    public void Destroy() {
        if (!destroyed)
            body.getWorld().destroyBody(body);
        destroyed = true;
    }

    public void setTriggered() {
        body.getFixtureList().get(0).setSensor(true);
    }
}
