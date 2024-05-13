package me.bigcubecat.game.uiObjects;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import me.bigcubecat.game.AssetManager.GameAssetModel;
import me.bigcubecat.game.Utils.Constants;

public class UiTimer implements IStageUI {
    private GameAssetModel gameAssetModel = GameAssetModel.getInstance();
    private Sprite borderSprite;
    private Sprite[] digits = new Sprite[4];
    private int[] intDigits = new int[4];

    float xPos = 0;
    float yPos = 0;
    int minutes = 0;
    int seconds = 0;

    public UiTimer() {
        borderSprite = new Sprite(gameAssetModel.getUITexture("timer_border"));
        float scaleFactor = Constants.SCALE_FACTOR * Constants.SCALE_FACTOR;
        borderSprite.scale(scaleFactor);
        xPos = Gdx.graphics.getWidth() / 2f - borderSprite.getWidth() / 2f;
        yPos = borderSprite.getWidth();
        borderSprite.setPosition(xPos, yPos);

        for (int i = 0; i < 4; ++i) {
            digits[i] = new Sprite(gameAssetModel.getUITexture("0"));
            digits[i].setScale(Constants.SCALE_FACTOR * Constants.SCALE_FACTOR);
        }
        // это не просто магические числа
        // они волшебные
        digits[0].setPosition(xPos - 12 * scaleFactor, yPos);
        digits[1].setPosition(xPos - 4 * scaleFactor, yPos);
        digits[2].setPosition(xPos + 10 * scaleFactor, yPos);
        digits[3].setPosition(xPos + 18 * scaleFactor, yPos);
    }

    public void setTime(float time) {
        int seconds = (int) time;
        this.minutes = seconds / 60;
        intDigits[0] = this.minutes / 10;
        intDigits[1] = this.minutes % 10;
        this.seconds = seconds % 60;
        intDigits[2] = this.seconds / 10;
        intDigits[3] = this.seconds % 10;
    }

    @Override
    public void render(SpriteBatch batch) {
        borderSprite.draw(batch);
        for (int i = 0; i < 4; ++i) {
            digits[i].setTexture(gameAssetModel.getUITexture("" + intDigits[i]));
            digits[i].draw(batch);
        }
    }
}
