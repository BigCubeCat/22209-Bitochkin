package ru.nsu.Operators.Util;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.Operators.Exceptions.InvalidCountVariablesException;

public class PushOperator implements IAbstractUtilOperator {
    @Override
    public int CountVariables() {
        return 1;
    }

    @Override
    public void Exec(CalcContext ctx, String[] args) throws InvalidCountVariablesException, UnknowVariableException {
        if (args.length != CountVariables()) throw new InvalidCountVariablesException();
        var value = ctx.GetVariable(args[0]);
        ctx.Push(value);
    }

    @Override
    public boolean IsOutput() {
        return false;
    }
}
