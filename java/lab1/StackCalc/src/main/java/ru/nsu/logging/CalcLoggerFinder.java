package ru.nsu.logging;

public class CalcLoggerFinder {

    public static System.Logger getLogger(String name, Module module) {
        return new CalcLogger();
    }
}

