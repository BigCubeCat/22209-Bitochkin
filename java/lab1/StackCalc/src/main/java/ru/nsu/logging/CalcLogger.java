package ru.nsu.logging;

import java.text.MessageFormat;
import java.util.ResourceBundle;

public class CalcLogger implements System.Logger {
    private String loggerName;

    public CalcLogger(String name) {
        loggerName = name;
    }

    @Override
    public String getName() {
        return loggerName;
    }

    @Override
    public boolean isLoggable(Level level) {
        return true;
    }

    @Override
    public void log(Level level, ResourceBundle bundle, String msg, Throwable thrown) {
        System.out.printf(getName() + "\t: log [%s] :\t%s - %s%n", level, msg, thrown);
    }

    @Override
    public void log(Level level, ResourceBundle bundle, String format, Object... params) {
        System.out.printf(getName() + "\t: log [%s] :\t%s%n", level, MessageFormat.format(format, params));
    }
}
