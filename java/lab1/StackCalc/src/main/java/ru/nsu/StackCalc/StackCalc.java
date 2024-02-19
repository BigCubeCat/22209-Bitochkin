package ru.nsu.StackCalc;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.Operators.Exceptions.InvalidCountVariablesException;
import ru.nsu.Operators.OperatorFactory;
import ru.nsu.logging.CalcLoggerFinder;

import java.util.Arrays;
import java.util.EmptyStackException;

public class StackCalc {
    private final OperatorFactory factory;
    private final CalcContext ctx;

    private final System.Logger logger = CalcLoggerFinder.getLogger("stack_calc", this.getClass().getModule());

    public StackCalc() {
        factory = new OperatorFactory();
        ctx = new CalcContext();
    }

    public void RunCommand(String[] args) {
        var argsWithoutCommand = Arrays.copyOfRange(args, 1, args.length);
        if (!factory.isCommand(args[0])) {
            return;
        }
        var operator = factory.getCommand(args[0], argsWithoutCommand);
        try {
            operator.Exec(ctx, argsWithoutCommand);
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
