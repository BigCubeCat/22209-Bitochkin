package me.bigcubecat.game.GameView;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.math.MathUtils;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.math.Vector3;
import me.bigcubecat.game.Utils.Constants;

public class GameCamera extends OrthographicCamera {
    int worldWidth;
    int worldHeight;
    float effectiveViewportWidth;
    float effectiveViewportHeight;

    Vector2 worldCenterPosition = new Vector2();
    Vector2 cornerPosition = new Vector2();

    Vector3 tmpVector = new Vector3();
    Vector2 mousePosition = new Vector2(0, 0);
    Vector2 uiCorner = new Vector2();


    public GameCamera() {
        super(Gdx.graphics.getWidth(), Gdx.graphics.getHeight());
        worldWidth = Gdx.graphics.getWidth();
        worldHeight = Gdx.graphics.getHeight();

        effectiveViewportWidth = viewportWidth * zoom;
        effectiveViewportHeight = viewportHeight * zoom;

        position.set(viewportWidth / 2f, viewportHeight / 2f, 0);
        projection.scl(Constants.PIXELS_TO_METERS);

        update();
    }

    public void UpdatePosition(Vector2 pos) {
        worldCenterPosition = pos;

        tmpVector.x = Gdx.input.getX();
        tmpVector.y = Gdx.input.getY();
        tmpVector.z = 0;
        unproject(tmpVector);
        mousePosition.x = tmpVector.x;
        mousePosition.y = tmpVector.y;

        position.x = MathUtils.clamp(
                pos.x,
                effectiveViewportWidth / 2f,
                Constants.MAX_CAMERA_WIDTH - effectiveViewportWidth / 2f
        );
        position.y = MathUtils.clamp(
                pos.y,
                effectiveViewportHeight / 2f,
                Constants.MAX_CAMERA_HEIGHT - effectiveViewportHeight / 2f
        );

        cornerPosition.set(position.x - viewportWidth / 2f, position.y - viewportHeight / 2f);
        update();
    }

    public Vector2 getWorldPosition() {
        return new Vector2(
                worldCenterPosition.x + viewportWidth / 2f,
                worldCenterPosition.y + viewportHeight / 2f
        );
    }

    public Vector2 getMousePosition() {
        return mousePosition;
    }

    public Vector2 getCorner() {
        return cornerPosition;
    }

    public void resize(int width, int height) {
        //viewportWidth = worldWidth * ((float) width / worldWidth);
        //viewportHeight = worldHeight * ((float) height / worldHeight);
        update();
    }

    public boolean inBounds(Vector2 pos) {
        if (pos.x < (position.x - viewportWidth) || pos.x > (position.x + viewportWidth)) {
            return false;
        }
        if (pos.y < (position.y - viewportHeight) || pos.y > (position.y + viewportHeight)) {
            return false;
        }
        return true;
    }
}
