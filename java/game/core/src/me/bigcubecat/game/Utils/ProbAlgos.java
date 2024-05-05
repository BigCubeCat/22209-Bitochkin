package me.bigcubecat.game.Utils;

public class ProbAlgos {
    public static double NormalDistribution(double t, double sigma) {
        return (1 / (sigma * Math.sqrt(2 * Math.PI))) * Math.exp(-(t * t) / (2 * sigma * sigma));
    }

    public static double LinearDistribution(double t, double b) {
        return t / b;
    }

    public static int randrange(int begin, int end) {
        int size = end - begin;
        return begin + (int) (random() * size);
    }

    public static boolean ExpSpawn(float time) {
        return ExpSpawn(time, Constants.TIME_DELAY);
    }

    public static boolean ExpSpawn(float time, float k) {
        double x = random();
        double y = (Math.exp(time / k) - 1) / k;
        return x <= y;
    }

    public static double random() {
        return Math.random();
    }
}
