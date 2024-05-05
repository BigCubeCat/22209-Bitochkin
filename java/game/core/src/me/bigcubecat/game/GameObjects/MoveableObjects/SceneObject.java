package me.bigcubecat.game.GameObjects.MoveableObjects;

import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.World;
import me.bigcubecat.game.GameObjects.AnimatedObjects.AnimatedObject;
import me.bigcubecat.game.GameObjects.AnimatedObjects.ObjectAnimation;
import me.bigcubecat.game.GameObjects.PhysicObject.BodyConf;
import me.bigcubecat.game.GameObjects.PhysicObject.PhysicObject;

public class SceneObject {
    String tag;
    AnimatedObject animatedObject;
    PhysicObject physicObject;
    int realSize;
    Vector2 position = new Vector2();
    BodyConf bodyConf;
    private boolean alive = true;

    public SceneObject() {
    }

    public SceneObject(MoveableConf conf) {
        Setup(conf);
    }

    public void Setup(MoveableConf conf) {
        Setup(conf.objectAnimation, conf.bodyConf, conf.world, conf.position);
    }

    public void Setup(
            ObjectAnimation anime,
            BodyConf bodyConfig,
            World box2dWorld,
            Vector2 pos
    ) {
        position = pos;
        bodyConf = bodyConfig;
        realSize = (int) bodyConf.radius * 2;
        animatedObject = new AnimatedObject(realSize, realSize);
        animatedObject.loadAnimation(anime);
        physicObject = new PhysicObject(box2dWorld, position, bodyConf);
    }

    public void Update() {
    }

    public void Move(float x, float y) {
        physicObject.move(x, y);
        updatePosition();
    }

    void updatePosition() {
        position = physicObject.getPosition();
        animatedObject.setPosition(position.x - bodyConf.radius, position.y - bodyConf.radius);
    }

    public void render(SpriteBatch batch, Vector2 cornerPosition) {
        animatedObject.setSpritePosition(position, cornerPosition);

        animatedObject.nextFrame();
        animatedObject.render(batch);
    }

    public Vector2 getPosition() {
        return position;
    }

    public void setHpObject(Object obj) {
        physicObject.setObject(obj);
    }

    public void Destroy() {
        physicObject.Destroy();
        alive = false;
    }

    public boolean isAlive() {
        return alive;
    }
}
