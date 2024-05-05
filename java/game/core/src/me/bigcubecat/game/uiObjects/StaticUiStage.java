package me.bigcubecat.game.uiObjects;

import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import me.bigcubecat.game.GameView.GameCamera;

import java.util.HashMap;

public class StaticUiStage {
    public Stage currentStage = Stage.WELCOME_STAGE;
    public GameSceneUI sceneUI;
    public HashMap<Stage, TempUiStage> staticStages = new HashMap<>();

    public StaticUiStage(GameCamera camera) {
        sceneUI = new GameSceneUI(camera);
        staticStages.put(Stage.WELCOME_STAGE, new WelcomeStageUI());
        staticStages.put(Stage.LOOSE_STAGE, new LooseStageUI());
        staticStages.put(Stage.WIN_STAGE, new WinStageUI());
        staticStages.put(Stage.PAUSE_STAGE, new PauseStageUI());
    }

    public void render(SpriteBatch batch) {
        if (currentStage != Stage.GAME_STAGE) { // сцена игры рендериться в RenderController
            TempUiStage st = staticStages.get(currentStage);
            if (st == null) return;
            if (st.isLeaving()) {
                st.reset();
                currentStage = st.getNextStage();
                System.out.println(currentStage);
                st = staticStages.get(currentStage);
            }
            if (st != null)
                st.render(batch);
        }
    }
}
