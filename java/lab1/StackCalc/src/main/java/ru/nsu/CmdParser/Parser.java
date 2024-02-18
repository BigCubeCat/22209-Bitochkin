package ru.nsu.CmdParser;


import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.Operators.InvalidCountVariablesException;
import ru.nsu.StackCalc.StackCalc;
import ru.nsu.logging.CalcLoggerFinder;

public class Parser {
    public StackCalc calc;

    private final System.Logger logger = CalcLoggerFinder.getLogger("parser", this.getClass().getModule());

    public Parser() {
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
