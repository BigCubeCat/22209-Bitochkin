package me.bigcubecat.game.Utils;

public class Constants {
    public static int SCALE_FACTOR = 2;
    public static int TILE_SIZE = 16;
    public static float PIXELS_TO_METERS = SCALE_FACTOR * TILE_SIZE;

    // BOX2D setup
    public static boolean DEBUG = false;
    public static float BOX2D_TIME_STEP = 1 / 60f;
    public static int BOX2D_VELOCITY_INTERATIONS = 6;
    public static int BOX2D_POSITION_ITERATIONS = 20;

    // Game Process Setup
    public static int WIN_TIME = 60 * 2;
    public static int TIME_DELAY = 50;
    public static int TIME_TO_REVIVAL = 2;
    public static float ACCELERATION = 10f;
    public static float MINIMUM_DELAY = 5;
    public static float MINIMUM_ATTACK = 0.1f;
    public static float ENEMY_HP = 15f;
    public static float ENEMY_POWER = 4f;
    public static float HEAL_SPEED = 2f;
    public static float TOWER_HP = 500f;
    public static float TOWER_POWER = 10f;
    public static float PLAYER_HP = 100;
    public static float PLAYER_POWER = 10;

    // Names
    public static String FIREBALL_NAME = "pfireball";
    public static String POWER_NAME = "power";
    public static String PLAYER_OBJECT_NAME = "player";
    public static String TOWER_OBJECT_NAME = "tower";
    public static String[] ENEMY_TYPES = {"enemy1"};

    // Camera
    public static int MAX_CAMERA_WIDTH = TILE_SIZE * SCALE_FACTOR * 90;
    public static int MAX_CAMERA_HEIGHT = TILE_SIZE * SCALE_FACTOR * 60;

    // ANIMATION
    public static float ANIME_DURATION = 1.5f;

    // Gun
    public static float COOLDOWN = 0.3f;
    public static float POWER_COOLDOWN = 0.5f;
    public static float FIREBALL_DISTANCE = 48f;
    public static float FIREBALL_POWER = 90f;
    public static float POWER_POWER = 500f;
    public static float POWER_HP = 100000f;
}
