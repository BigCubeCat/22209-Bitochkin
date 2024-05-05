package me.bigcubecat.game.uiObjects;

import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;
import me.bigcubecat.game.AssetManager.GameAssetModel;
import me.bigcubecat.game.Utils.Constants;

public class Aim {
    public Vector2 aimDirection = new Vector2();
    private Texture aimTexture;
    private Sprite sprite;

    private Vector2 pos = new Vector2();
    private float angle;
    private float halfHeight = 0;
    private float halfWidth = 0;

    public Aim() {
        GameAssetModel assetModel = GameAssetModel.getInstance();
        aimTexture = assetModel.getUITexture("aim");

        sprite = new Sprite(aimTexture);
        sprite.setScale(Constants.SCALE_FACTOR);
        sprite.setAlpha(0.5f);

        halfHeight = sprite.getHeight() / 2f;
        halfWidth = sprite.getWidth() / 2f;
    }

    public void render(SpriteBatch batch) {
        sprite.setPosition(pos.x, pos.y);
        sprite.setRotation(angle);
        sprite.draw(batch);
    }

    public void update() {
        angle = aimDirection.angleDeg();
    }

    public void setPosition(Vector2 p, Vector2 corner) {
        pos.x = p.x - corner.x - halfWidth;
        pos.y = p.y - corner.y - halfHeight;
    }

    public float getAngle() {
        return angle;
    }
}
