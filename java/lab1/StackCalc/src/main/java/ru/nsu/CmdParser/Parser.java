package ru.nsu.CmdParser;


import ru.nsu.logging.CalcLoggerFinder;

import java.util.Arrays;
import java.util.Objects;

public class Parser {

    private final System.Logger logger = CalcLoggerFinder.getLogger("parser", this.getClass().getModule());

    public CalcConfig ParseCommand(String command) {
        CalcConfig config = new CalcConfig();
        config.pass = true;
        String[] args = command.split(" ");
        if (args.length == 0) {
            logger.log(System.Logger.Level.INFO, "empty string");
            return config;
        } else if (Objects.equals(args[0], "#")) {
            logger.log(System.Logger.Level.INFO, "comment");
            return config;
        }
        logger.log(System.Logger.Level.INFO, "parsed command: " + command);
        config.pass = false;
        config.cmd = args[0];
        config.args = Arrays.copyOfRange(args, 1, args.length);
        return config;
    }
}
