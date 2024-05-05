package me.bigcubecat.game.uiObjects;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import me.bigcubecat.game.AssetManager.GameAssetModel;
import me.bigcubecat.game.GameControl.InputController;

public class TempUiStage implements IStageUI {
    private InputController ic;
    private Stage nextStage;
    Sprite sprite;
    BitmapFont font = new BitmapFont();
    float xPos;
    float yPos;
    String help;
    private boolean leave = false;

    public TempUiStage(String screenName, String helpText, Stage nextStage) {
        ic = InputController.getInstance();
        sprite = new Sprite(GameAssetModel.getInstance().getUITexture(screenName));
        sprite.setPosition(0, 0);
        xPos = Gdx.graphics.getWidth() / 2f - 50;
        yPos = Gdx.graphics.getHeight() / 2f - 150;
        help = helpText;
        this.nextStage = nextStage;
    }

    @Override
    public void render(SpriteBatch batch) {
        sprite.draw(batch);
        font.draw(batch, help, xPos, yPos);
        if (ic.checkChangeStage()) {
            leave = true;
        }
    }

    public Stage getNextStage() {
        return nextStage;
    }
    public boolean isLeaving() {
        return leave;
    }

    public void reset() {
        leave = false;
    }
}
