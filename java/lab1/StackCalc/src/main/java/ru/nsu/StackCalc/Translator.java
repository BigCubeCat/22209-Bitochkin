package ru.nsu.StackCalc;

import ru.nsu.CmdParser.InputReader;
import ru.nsu.CmdParser.Parser;
import ru.nsu.Main;
import ru.nsu.logging.CalcLoggerFinder;

import java.lang.reflect.InvocationTargetException;

public class Translator {
    InputReader reader;
    Parser parser;

    StackCalc calc;
    private static final System.Logger logger = CalcLoggerFinder.getLogger("translator", Main.class.getModule());
    public Translator(InputReader r) throws ClassNotFoundException, InvocationTargetException, NoSuchMethodException, InstantiationException, IllegalAccessException {
        reader = r;
        parser = new Parser();
        calc = new StackCalc();
    }

    public void Run() {
        while (!reader.IsEnd()) {
            String command = reader.ReadCmd();

            logger.log(System.Logger.Level.INFO, "command=" + command);

            var config = parser.ParseCommand(command);

            calc.RunCommand(config);

        }
    }
}
