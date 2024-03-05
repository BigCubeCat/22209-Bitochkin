package ru.nsu.StackCalc;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.CmdParser.CalcConfig;
import ru.nsu.Operators.Exceptions.InvalidCountVariablesException;
import ru.nsu.Operators.OperatorFactory;
import ru.nsu.Operators.OperatorInterface;
import ru.nsu.logging.CalcLoggerFinder;

import java.lang.reflect.InvocationTargetException;
import java.util.EmptyStackException;

public class StackCalc {
    private final OperatorFactory factory;
    private final CalcContext ctx;

    private final System.Logger logger = CalcLoggerFinder.getLogger("stack_calc", this.getClass().getModule());

    public StackCalc() {
        factory = new OperatorFactory();
        ctx = new CalcContext();
    }

    public void RunCommand(CalcConfig config) {
        if (config.pass) return;

        if (!factory.isCommand(config.cmd)) {
            return;
        }
        OperatorInterface operator;
        try {
            operator = factory.getCommand(config.cmd);
        } catch (ClassNotFoundException | InvocationTargetException | NoSuchMethodException | InstantiationException |
                 IllegalAccessException e) {
            logger.log(System.Logger.Level.ERROR, e.toString());
            logger.log(System.Logger.Level.ERROR, "cant load command");
            return;
        }
        try {
            operator.Exec(ctx, config.args);
        } catch (EmptyStackException e) {
            logger.log(System.Logger.Level.ERROR, "stack is empty");
        } catch (UnknowVariableException e) {
            logger.log(System.Logger.Level.ERROR, "unknown variable name");
        } catch (InvalidCountVariablesException e) {
            logger.log(System.Logger.Level.ERROR, "invalid count variables");
        }
        if (operator.IsOutput()) {
            System.out.println(ctx.GetOut());
        }
    }
}
