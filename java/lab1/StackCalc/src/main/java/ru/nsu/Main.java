package ru.nsu;

import ru.nsu.CmdParser.InputReader;
import ru.nsu.CmdParser.Parser;
import ru.nsu.logging.CalcLoggerFinder;

import java.io.FileNotFoundException;
import java.lang.reflect.InvocationTargetException;

public class Main {
    private static final System.Logger logger = CalcLoggerFinder.getLogger("main", this.getClass().getModule());
    public static void main(String[] args) throws FileNotFoundException, ClassNotFoundException, InvocationTargetException, NoSuchMethodException, InstantiationException, IllegalAccessException {
        Parser view = new Parser();
        InputReader ir = null;

        if (args.length == 0) {
            ir = new InputReader();
        } else {
            ir = new InputReader(args[0]);
        }

        while (!ir.IsEnd()) {
            String command = ir.ReadCmd();
            logger.log(System.Logger.Level.INFO, "command=" + command);
            view.ExecCommand(command);
        }
    }
}