package me.bigcubecat.game.GameControl;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.controllers.Controller;
import com.badlogic.gdx.controllers.Controllers;
import com.badlogic.gdx.math.Vector2;

public class InputController {
    private static InputController INSTANCE;
    Controller controller;
    private boolean hasController = false;
    public Vector2 speed = new Vector2(0, 0);
    public Vector2 direction = new Vector2(0, 0);
    public boolean shoot = false;
    public boolean power = false;
    public boolean[] changeStage = new boolean[]{false, false};

    private InputController() {
        CheckController();
    }

    public static InputController getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new InputController();
        }
        return INSTANCE;
    }

    public void CheckController() {
        if (Controllers.getControllers().size == 0) {
            hasController = false;
        } else {
            controller = Controllers.getControllers().first();
            hasController = true;
        }
    }

    public void reset() {
        shoot = false;
        power = false;
        changeStage[0] = false;
        changeStage[1] = false;
        speed.x = 0;
        speed.y = 0;
    }

    public Vector2 getDirection(Vector2 pos) {
        if (hasController)
            return direction;
        direction.x = pos.x - Gdx.input.getX(); //(int)pos.x);
        direction.y = Gdx.input.getY((int) pos.y);
        return direction;
    }

    public boolean useController() {
        return hasController;
    }

    public void HandleAction() {
        reset();
        if (hasController) {
            handleControllers();
        } else {
            handleWASD();
        }
    }

    private void handleControllers() {
        speed.x = (float) ((int) (controller.getAxis(0) * 100)) / 100;
        speed.y = -(float) ((int) (controller.getAxis(1) * 100)) / 100;

        direction.x = controller.getAxis(2);
        direction.y = controller.getAxis(3);

        shoot = controller.getAxis(4) != 0;
    }

    private void handleWASD() {
        if (Gdx.input.isKeyPressed(Input.Keys.SPACE)) {
            changeStage[0] = true;
        }
        if (Gdx.input.isKeyPressed(Input.Keys.W)) {
            speed.y = 1;
        }
        if (Gdx.input.isKeyPressed(Input.Keys.S)) {
            speed.y = -1;
        }
        if (Gdx.input.isKeyPressed(Input.Keys.A)) {
            speed.x = -1;
        }
        if (Gdx.input.isKeyPressed(Input.Keys.D)) {
            speed.x = 1;
        }
        if (Gdx.input.isButtonPressed(Input.Buttons.LEFT)) {
            shoot = true;
            changeStage[1] = true;
        }
        if (Gdx.input.isButtonPressed(Input.Buttons.RIGHT)) {
            power = true;
        }
    }

    public boolean toggleScene(int index) {
        if (changeStage[index]) {
            changeStage[index] = false;
            return true;
        }
        return false;
    }
}
