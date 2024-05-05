package me.bigcubecat.game.GameControl;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Cursor;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import me.bigcubecat.game.GameObjects.Scene.PlayResult;
import me.bigcubecat.game.GameObjects.Scene.SceneController;
import me.bigcubecat.game.GameView.GameCamera;
import me.bigcubecat.game.Utils.GameLoggerFinder;
import me.bigcubecat.game.uiObjects.Stage;
import me.bigcubecat.game.uiObjects.StaticUiStage;

public class GameController {
    private final System.Logger logger = GameLoggerFinder.getLogger("game_controller", this.getClass().getModule());
    InputController inputController;
    RenderController renderController;
    Box2DController physicController;
    GameCamera camera;
    SceneController sceneController;
    StaticUiStage ui;

    public GameController(
    ) {
        Gdx.graphics.setSystemCursor(Cursor.SystemCursor.Arrow);
        physicController = Box2DController.getInstance();
        inputController = InputController.getInstance();
        camera = new GameCamera();
        renderController = new RenderController(camera, physicController.getWorld());
        ui = new StaticUiStage(camera);
        generateGameScene();
    }

    private void generateGameScene() {
        sceneController = new SceneController(physicController, camera);
        sceneController.setSpawners(renderController.getSpawners());
    }

    public void Update() {
        inputController.HandleAction();

        SpriteBatch batch = renderController.getBatch();

        renderController.renderTileMap();
        batch.begin();

        if (ui.currentStage != Stage.GAME_STAGE) {
            ui.render(renderController.getBatch());
        } else {
            if (sceneController.result == PlayResult.WIN) {
                ui.currentStage = Stage.WIN_STAGE;
                generateGameScene();
            } else if (sceneController.result == PlayResult.LOOSE) {
                ui.currentStage = Stage.LOOSE_STAGE;
                generateGameScene();
            } else if (sceneController.result == PlayResult.PAUSE) {
                ui.currentStage = Stage.PAUSE_STAGE;
                sceneController.result = PlayResult.IN_PROCESS;
            } else if (sceneController.result == PlayResult.IN_PROCESS) {
                camera.UpdatePosition(sceneController.getPlayerPosition());
                camera.update();
                sceneController.setMousePosition(camera.getMousePosition());
                sceneController.Update();
                sceneController.render(batch, camera.getCorner());
                ui.sceneUI.setSliderData(sceneController.playerHP());
                ui.sceneUI.Update(sceneController.getGameTimer());
                ui.sceneUI.render(renderController.getBatch());
                physicController.Update(camera);
            }
        }

        batch.end();
    }

    public void resize(int width, int height) {
        camera.resize(width, height);
    }
}
