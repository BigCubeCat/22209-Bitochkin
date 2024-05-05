package me.bigcubecat.game.GameObjects.BattleObjects;

import com.badlogic.gdx.Gdx;
import me.bigcubecat.game.Utils.Constants;

import java.lang.module.Configuration;

public class HPObject {
    public String Tag;
    public float power = 0;
    private float healPoints = 0;
    private float maximumHP = 100;
    private float dieCounter = 0;
    private float healSpeed = Constants.HEAL_SPEED;

    public HPObject(String tag, float hp) {
        maximumHP = hp;
        healPoints = hp;
        Tag = tag;
    }

    public float getHp() {
        return healPoints;
    }

    public float blendPercent() {
        float blend = (healPoints / maximumHP);
        if (blend < 0.5) {
            return 0.5f;
        }
        return blend;
    }

    public void heal(float p) {
        healPoints += p;
        if (healPoints > maximumHP) {
            healPoints = maximumHP;
        }
    }

    public void attack(float p) {
        healPoints -= p;
        if (healPoints < 0) {
            healPoints = 0;
        }
    }

    public float getHealSpeed() {
        return healSpeed;
    }

    public boolean isAlive() {
        return healPoints > 0;
    }

    public void increaseCounter() {
        dieCounter += Gdx.graphics.getDeltaTime();
    }

    public boolean destroy() {
        return dieCounter >= Constants.ANIME_DURATION;
    }

    public float hpPercent() {
        return healPoints / maximumHP;
    }
}
