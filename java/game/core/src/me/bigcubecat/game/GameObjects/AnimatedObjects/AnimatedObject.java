package me.bigcubecat.game.GameObjects.AnimatedObjects;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Animation;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.math.Vector2;
import me.bigcubecat.game.Utils.GameLoggerFinder;

import java.util.HashMap;
import java.util.Map;

public class AnimatedObject {
    String tag;
    private Sprite sprite = new Sprite();
    private String currentAnimation;
    private int spriteWidth = 16, spriteHeight = 16;
    private HashMap<String, Animation<TextureRegion>> animatorStates = new HashMap<>();
    public TextureRegion currentFrame;
    private float stateTime;
    private Vector2 position = new Vector2();
    private boolean loopAnimation = true;

    public AnimatedObject(int width, int height) {
        spriteWidth = width;
        spriteHeight = height;
        stateTime = 0f;
    }

    public void loadAnimation(ObjectAnimation objectAnimation) {
        for (Map.Entry<String, TileAtlasConf> entry : objectAnimation.states.entrySet()) {
            addAnimation(entry.getValue());
        }
    }

    public void addAnimation(TileAtlasConf atlasConf) {
        addAnimation(
                atlasConf.name, atlasConf.tileAtlas, atlasConf.frameDuration,
                atlasConf.countRows, atlasConf.countCols,
                atlasConf.startRow, atlasConf.startCol);
    }

    public void addAnimation(
            String name, Texture tileAtlas, float frameDuration,
            int countRows, int countCols,
            int startRow, int startCol
    ) {
        int tileWidth = tileAtlas.getWidth() / countCols;
        int tileHeight = tileAtlas.getHeight() / countRows;

        TextureRegion[][] tmp = TextureRegion.split(tileAtlas, tileWidth, tileHeight);

        TextureRegion[] frames = new TextureRegion[countCols * countRows];
        int index = 0;
        for (int i = startRow; i < countRows; i++) {
            for (int j = startCol; j < countCols; j++) {
                frames[index++] = tmp[i][j];
            }
        }
        animatorStates.put(name, new Animation<>(frameDuration, frames));
    }

    public void setCurrentAnimation(String animation, boolean loop) {
        loopAnimation = loop;
        setCurrentAnimation(animation);
    }
    public void setCurrentAnimation(String animation) {
        if (animatorStates.containsKey(animation)) {
            currentAnimation = animation;
        }
    }

    public void setPosition(float x, float y) {
        position.x = x;
        position.y = y;
    }

    public void setSpritePosition(Vector2 position, Vector2 corner) {
        sprite.setPosition(
                position.x - corner.x - ((float) spriteWidth / 2),
                position.y - corner.y - ((float) spriteHeight / 2)
        );
    }

    public void nextFrame() {
        if (currentAnimation == null) {
            System.out.println("current Animation is null");
            return;
        }
        stateTime += Gdx.graphics.getDeltaTime();
        currentFrame = animatorStates.get(currentAnimation).getKeyFrame(stateTime, loopAnimation);
        sprite.setRegion(currentFrame, 0, 0, 16, 16);
        sprite.setSize(spriteWidth, spriteHeight);
    }

    public void render(SpriteBatch batch) {
        sprite.draw(batch);
    }

    public void setBlend(float blend) {
        sprite.setAlpha(blend);
    }
}
