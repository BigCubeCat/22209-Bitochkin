package me.bigcubecat.game.GameObjects.BattleObjects;

import com.badlogic.gdx.physics.box2d.*;
import me.bigcubecat.game.AssetManager.GameAssetModel;
import me.bigcubecat.game.GameObjects.PhysicObject.BodyConf;
import me.bigcubecat.game.Utils.Constants;

public class Tower extends HPObject {
    Body body;

    public Tower(World world, BodyConf bodyConf) {
        super("pTower", Constants.TOWER_HP);
        power = 10;

        BodyDef bd = new BodyDef();
        bd.type = BodyDef.BodyType.KinematicBody;
        body = world.createBody(bd);
        body.setUserData(this);

        CircleShape circle = new CircleShape();
        circle.setRadius(bodyConf.radius);

        System.out.println(bodyConf);

        FixtureDef fd = new FixtureDef();
        fd.shape = circle;
        fd.density = bodyConf.density;
        fd.friction = bodyConf.friction;
        fd.restitution = bodyConf.restitution;
        fd.isSensor = true;

        body.createFixture(fd);

        body.setTransform(GameAssetModel.getInstance().findTower(), 0);
    }

    @Override
    public void heal(float p) {
        return;
    }
}
