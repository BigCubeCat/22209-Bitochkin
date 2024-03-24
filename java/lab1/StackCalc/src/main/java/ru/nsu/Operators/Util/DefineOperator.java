package ru.nsu.Operators.Util;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.Operators.Exceptions.InvalidCountVariablesException;

public class DefineOperator implements IAbstractUtilOperator {
    @Override
    public void Exec(CalcContext ctx, String[] args) throws InvalidCountVariablesException {
        if (args.length != CountVariables()) {
            throw new InvalidCountVariablesException();
        }
        Double num = Double.parseDouble(args[1]);
        ctx.SetVariable(args[0], num);
    }

    @Override
    public int CountVariables() {
        return 2;
    }

    @Override
    public boolean IsOutput() {
        return false;
    }
}
