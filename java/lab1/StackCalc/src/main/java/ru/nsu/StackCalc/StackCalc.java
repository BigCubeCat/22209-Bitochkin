package ru.nsu.StackCalc;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.Operators.InvalidCountVariablesException;
import ru.nsu.Operators.OperatorFactory;

import java.util.Arrays;

public class StackCalc {
    private OperatorFactory factory;
    private CalcContext ctx;

    public StackCalc() {
        factory = new OperatorFactory();
        ctx = new CalcContext();
    }

    public void RunCommand(String[] args) throws UnknowVariableException, InvalidCountVariablesException {
        var argsWithoutCommand = Arrays.copyOfRange(args, 1, args.length);
        if (!factory.isCommand(args[0])) {
            return;
        }
        var operator = factory.getCommand(args[0], argsWithoutCommand);
        operator.Exec(ctx, argsWithoutCommand);
        if (operator.IsOutput()) {
            System.out.println(ctx.GetOut());
        }
    }
}
