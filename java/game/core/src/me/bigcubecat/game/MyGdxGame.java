package me.bigcubecat.game;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL20;
import me.bigcubecat.game.GameControl.GameController;

public class MyGdxGame extends ApplicationAdapter {
    GameController gameController;

    @Override
    public void create() {
        gameController = new GameController();
    }

    @Override
    public void render() {
        Gdx.gl.glClearColor(22, 23, 23, 0);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
        gameController.Update();
    }

    @Override
    public void resize(int width, int height) {
    }
}
