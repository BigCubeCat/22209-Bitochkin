package ru.nsu.logging;

import java.text.MessageFormat;
import java.util.ResourceBundle;

public class CalcLogger implements System.Logger {

    @Override
    public String getName() {
        return "CalcLogger";
    }

    @Override
    public boolean isLoggable(Level level) {
        return true;
    }

    @Override
    public void log(Level level, ResourceBundle bundle, String msg, Throwable thrown) {
        System.out.printf("log [%s]: %s - %s%n", level, msg, thrown);
    }

    @Override
    public void log(Level level, ResourceBundle bundle, String format, Object... params) {
        System.out.printf("log [%s]: %s%n", level, MessageFormat.format(format, params));
    }
}
