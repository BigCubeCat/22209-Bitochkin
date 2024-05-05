package me.bigcubecat.game.GameObjects.Scene;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.utils.Array;
import me.bigcubecat.game.AssetManager.GameAssetModel;
import me.bigcubecat.game.GameControl.Box2DController;
import me.bigcubecat.game.GameControl.InputController;
import me.bigcubecat.game.GameObjects.BattleObjects.Tower;
import me.bigcubecat.game.GameObjects.MoveableObjects.MoveableConf;
import me.bigcubecat.game.GameObjects.MoveableObjects.MoveableFactory;
import me.bigcubecat.game.GameObjects.MoveableObjects.Player;
import me.bigcubecat.game.GameView.GameCamera;
import me.bigcubecat.game.Utils.Constants;
import me.bigcubecat.game.Utils.ProbAlgos;

public class SceneController {
    MoveableFactory moveableFactory;
    InputController inputController;
    Box2DController box2DController;
    GameCamera camera;
    Array<Vector2> spawnPoints;
    Array<Spawner> allSpawners;
    GameAssetModel assetModel;
    Player player;
    Tower tower;
    Vector2 hp;

    private float gameTimer;
    public PlayResult result;

    private float revivalCounter = 0;

    public SceneController(
            Box2DController physicController,
            GameCamera cam
    ) {
        inputController = InputController.getInstance();
        camera = cam;
        box2DController = physicController;
        moveableFactory = new MoveableFactory();
        spawnPoints = new Array<>();
        allSpawners = new Array<>();
        assetModel = GameAssetModel.getInstance();
        hp = new Vector2();
        gameTimer = Constants.WIN_TIME;
        result = PlayResult.IN_PROCESS;

        tower = new Tower(box2DController.getWorld(), assetModel.getPhysicType("tower"));
        createPlayer();
    }

    private void createPlayer() {
        revivalCounter = 0;
        try {
            player = (Player) moveableFactory.createObject(Constants.PLAYER_OBJECT_NAME,
                    new MoveableConf(
                            Constants.PLAYER_OBJECT_NAME,
                            box2DController.getWorld(),
                            assetModel.getObjectMapPosition(Constants.PLAYER_OBJECT_NAME)
                    )
            );
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public void setSpawners(Array<Vector2> spawners) {
        spawnPoints = spawners;
        String name;
        for (Vector2 point : spawnPoints) {
            name = Constants.ENEMY_TYPES[ProbAlgos.randrange(0, spawnPoints.size) % Constants.ENEMY_TYPES.length];
            allSpawners.add(new Spawner(box2DController.getWorld(), moveableFactory, name, point));
        }
    }

    public void Update() {
        if (inputController.checkChangeStage()) {
            result = PlayResult.PAUSE;
            return;
        }
        float deltaTime = Gdx.graphics.getDeltaTime();
        gameTimer -= deltaTime;
        if (gameTimer < 0) {
            result = PlayResult.WIN;
            clearScene();
            return;
        }
        if (!tower.isAlive()) {
            result = PlayResult.LOOSE;
            clearScene();
            return;
        }
        for (Spawner sp : allSpawners) {
            sp.Update(deltaTime, camera.getWorldPosition());
        }
        if (!player.isAlive()) {
            revivalCounter += deltaTime;
            if (revivalCounter > Constants.TIME_TO_REVIVAL) {
                createPlayer();
            }
        } else {
            player.Update();
            player.Move(inputController.speed.x, inputController.speed.y);
        }
    }

    public Vector2 getPlayerPosition() {
        if (player != null)
            return player.getPosition();
        return new Vector2(0, 0);
    }

    public void render(SpriteBatch batch, Vector2 corner) {
        player.render(batch, corner);
        for (Spawner sp : allSpawners) {
            sp.render(batch, corner);
        }
    }

    public void setMousePosition(Vector2 mousePosition) {
        player.updateViewDir(mousePosition);
    }

    public Vector2 playerHP() {
        hp.x = player.livePercent();
        hp.y = tower.hpPercent();
        return hp;
    }

    private void clearScene() {
        for (Spawner sp : allSpawners) {
            sp.Destroy();
        }
        player.Destroy();
    }

    public float getGameTimer() {
        return gameTimer;
    }
}
