package me.bigcubecat.game.GameObjects.AnimatedObjects;

public class PlayerAnimatedObject extends AnimatedObject {
    public PlayerAnimatedObject(ObjectAnimation objectAnimation, int tileSize) {
        super(tileSize, tileSize);
        loadAnimation(objectAnimation);
    }
}
