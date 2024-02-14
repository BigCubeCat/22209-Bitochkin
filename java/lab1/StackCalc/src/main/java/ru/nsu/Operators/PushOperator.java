package ru.nsu.Operators;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;

public class PushOperator implements AbstractOperator {
    @Override
    public int CountVariables() {
        return 1;
    }

    @Override
    public Double Exec(CalcContext ctx, String[] args) throws InvalidCountVariablesException, UnknowVariableException {
        if (args.length != CountVariables()) throw new InvalidCountVariablesException();
        var value = ctx.GetVariable(args[0]);
        ctx.Push(value);
        return 0.0;
    }
}
