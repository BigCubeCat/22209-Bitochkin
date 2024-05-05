package me.bigcubecat.game.AI;

import com.badlogic.gdx.math.Vector2;
import me.bigcubecat.game.AssetManager.GameAssetModel;
import me.bigcubecat.game.Utils.ProbAlgos;

// TODO: Сделать Муравьинный алгоритм

public class ChaoticAI extends AbstractAiAgent {
    GameAssetModel singleton = GameAssetModel.getInstance();
    Vector2 chaoticVector = new Vector2();
    Vector2 position = new Vector2();

    @Override
    public Vector2 getDirection() {
        Vector2 towerPosition = singleton.findTower();
        chaoticVector.x = towerPosition.x - position.x;
        chaoticVector.y = towerPosition.y - position.y;
        chaoticVector = chaoticVector.nor();
        chaoticVector.rotateDeg(ProbAlgos.randrange(-120, 120));
        return chaoticVector;
    }

    public Vector2 getDirection(Vector2 pos) {
        position = pos;
        getDirection();
        return chaoticVector;
    }
}
