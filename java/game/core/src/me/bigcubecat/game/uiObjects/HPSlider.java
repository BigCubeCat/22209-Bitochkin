package me.bigcubecat.game.uiObjects;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;
import me.bigcubecat.game.AssetManager.GameAssetModel;
import me.bigcubecat.game.GameView.GameCamera;

import java.nio.file.LinkPermission;

public class HPSlider {
    public float WINDOW_WIDTH = 100;
    public float WINDOW_HEIGHT = 100;
    public float hpPercent = 1000.3f;

    private GameCamera camera;

    Texture sliderTexture;
    Texture iconTexture;
    private Sprite sliderHp;

    private GameAssetModel gameAssetModel = GameAssetModel.getInstance();
    private float width = 0;
    private int leftGap;
    private int topGap;

    public HPSlider(GameCamera cam, Color color, int left, int top) {
        camera = cam;
        WINDOW_WIDTH = camera.viewportWidth;
        leftGap = left;
        topGap = top;

        sliderTexture = gameAssetModel.getUITexture("hp");
        iconTexture = gameAssetModel.getUITexture("hp");

        sliderHp = new Sprite(sliderTexture);
        sliderHp.setTexture(sliderTexture);

        sliderHp.setColor(color);
    }

    public void render(SpriteBatch batch) {
        Vector2 pos = camera.getCorner();
        width = hpPercent * Gdx.graphics.getWidth();
        sliderHp.setScale(width, 16);
        sliderHp.setPosition(width / 2, Gdx.graphics.getHeight() - topGap);
        sliderHp.draw(batch);
    }
}
