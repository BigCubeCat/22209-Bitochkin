package ru.nsu.Operators;

import ru.nsu.CalcContext.CalcContext;

public class DefineOperator implements AbstractOperator {
    @Override
    public Double Exec(CalcContext ctx, String[] args) throws InvalidCountVariablesException {
        if (args.length != CountVariables()) {
            throw new InvalidCountVariablesException();
        }
        Double num = Double.parseDouble(args[1]);
        ctx.SetVariable(args[0], num);
        return 0.0;
    }

    @Override
    public int CountVariables() {
        return 2;
    }
}
