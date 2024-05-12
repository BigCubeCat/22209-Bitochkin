package me.bigcubecat.game.GameControl;

import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.maps.MapObject;
import com.badlogic.gdx.maps.MapObjects;
import com.badlogic.gdx.maps.objects.RectangleMapObject;
import com.badlogic.gdx.maps.tiled.*;
import com.badlogic.gdx.maps.tiled.renderers.OrthogonalTiledMapRenderer;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.Body;
import com.badlogic.gdx.physics.box2d.BodyDef;
import com.badlogic.gdx.physics.box2d.PolygonShape;
import com.badlogic.gdx.physics.box2d.World;
import com.badlogic.gdx.utils.Array;
import me.bigcubecat.game.GameView.GameCamera;
import me.bigcubecat.game.Utils.Constants;

public class RenderController {
    private final GameCamera camera;
    private final TiledMapRenderer tiledMapRenderer;
    private final TiledMap tiledMap;
    private Array<Vector2> spawners = new Array<>();
    private SpriteBatch batch = new SpriteBatch();

    public RenderController(GameCamera cam, World world) {
        camera = cam;
        tiledMap = new TmxMapLoader().load("sprites/main.tmx");
        tiledMapRenderer = new OrthogonalTiledMapRenderer(tiledMap, Constants.SCALE_FACTOR);

        parseMap(world);
    }

    private static float coordToBox2D(float coord) {
        return coord * Constants.PIXELS_TO_METERS;
    }

    private void parseMap(World world) {
        TiledMapTileLayer layer = (TiledMapTileLayer) tiledMap.getLayers().get(0);
        for (int x = 0; x < layer.getWidth(); x++) {
            for (int y = 0; y < layer.getHeight(); y++) {
                TiledMapTileLayer.Cell cell = layer.getCell(x, y);
                if (cell == null)
                    continue;

                MapObjects cellObjects = cell.getTile().getObjects();
                if (cellObjects.getCount() != 1)
                    continue;

                MapObject mapObject = cellObjects.get(0);

                if (mapObject instanceof RectangleMapObject) {
                    RectangleMapObject rectangleObject = (RectangleMapObject) mapObject;
                    Rectangle rectangle = rectangleObject.getRectangle();

                    BodyDef bodyDef = getBodyDef(
                            coordToBox2D(x + 1) + rectangle.getX() - (Constants.PIXELS_TO_METERS - rectangle.getWidth()),
                            coordToBox2D(y + 1) + rectangle.getY() - (Constants.PIXELS_TO_METERS - rectangle.getHeight())
                    );

                    Body body = world.createBody(bodyDef);
                    PolygonShape polygonShape = new PolygonShape();
                    polygonShape.setAsBox(rectangle.getWidth(), rectangle.getHeight());
                    body.createFixture(polygonShape, 0.0f);
                    polygonShape.dispose();
                } else {
                    // it is spawner
                    spawners.add(new Vector2(coordToBox2D(x), coordToBox2D(y)));
                }
            }
        }
    }

    private BodyDef getBodyDef(float x, float y) {
        BodyDef bodyDef = new BodyDef();
        bodyDef.type = BodyDef.BodyType.StaticBody;
        bodyDef.position.set(x, y);

        return bodyDef;
    }

    public Array<Vector2> getSpawners() {
        return spawners;
    }

    public void renderTileMap() {
        tiledMapRenderer.setView(camera);
        tiledMapRenderer.render();
    }

    public SpriteBatch getBatch() {
        return batch;
    }
}
