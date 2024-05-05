package me.bigcubecat.game.GameObjects.PhysicObject;

public class BodyConf {
    public float mass = 0;
    public float speed = 0;
    public float radius = 0;
    public float density = 0;
    public float friction = 0;
    public float restitution = 0;

    public BodyConf(BodyConf conf) {
        mass = conf.mass;
        speed = conf.speed;
        radius = conf.radius;
        density = conf.density;
        friction = conf.friction;
        restitution = conf.restitution;
    }

    @Override
    public String toString() {
        return "---\nmass: " + mass + "\nspeed: " + speed + "\nradius: " + radius + "\ndensity: " + density + "\nfriction: " + friction + "\nrestitution: " + restitution + "\n---";
    }

    public BodyConf() {
    }
}
