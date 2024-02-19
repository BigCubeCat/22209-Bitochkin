package ru.nsu.CmdParser;


import ru.nsu.StackCalc.StackCalc;
import ru.nsu.logging.CalcLoggerFinder;

import java.lang.reflect.InvocationTargetException;

public class Parser {
    public StackCalc calc;

    private final System.Logger logger = CalcLoggerFinder.getLogger("parser", this.getClass().getModule());

    public Parser() throws ClassNotFoundException, InvocationTargetException, NoSuchMethodException, InstantiationException, IllegalAccessException {
        calc = new StackCalc();
    }

    public void ExecCommand(String command) {
        String[] args = command.split(" ");
        if (args.length == 0) {
            logger.log(System.Logger.Level.INFO, "empty string");
            return;
        } else if (args[0] == "#") {
            logger.log(System.Logger.Level.INFO, "comment");
            return;
        }
        logger.log(System.Logger.Level.INFO, "running command: " + command);
        calc.RunCommand(args);
    }
}
