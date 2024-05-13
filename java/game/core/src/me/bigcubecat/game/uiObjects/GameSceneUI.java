package me.bigcubecat.game.uiObjects;

import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;
import me.bigcubecat.game.GameView.GameCamera;

public class GameSceneUI implements IStageUI {
    HPSlider playerHpSlider;
    HPSlider towerHpSlider;
    UiTimer uiTimer;

    public GameSceneUI(GameCamera cam) {
        towerHpSlider = new HPSlider(cam, new Color(1, 1, 1, 0.8f), 0, 8);
        playerHpSlider = new HPSlider(cam, new Color(1, 1, 1, 0.8f), 0, 32);
        uiTimer = new UiTimer();
    }

    public void Update(float time) {
        uiTimer.setTime(time);
    }

    public void render(SpriteBatch batch) {
        playerHpSlider.render(batch);
        towerHpSlider.render(batch);
        uiTimer.render(batch);
    }

    public void setSliderData(Vector2 percent) {
        playerHpSlider.hpPercent = percent.x;
        towerHpSlider.hpPercent = percent.y;
    }
}
