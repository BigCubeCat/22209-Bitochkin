package ru.nsu.Operators.Util;

import ru.nsu.CalcContext.CalcContext;

public class PopOperator implements IAbstractUtilOperator {
    @Override
    public void Exec(CalcContext ctx, String[] args) {
        if (args.length == 0) {
            ctx.SetOut(ctx.Pop());
        } else if (args.length == 1) {
            double result = ctx.Pop();
            ctx.SetVariable(args[0], result);
        }
    }

    @Override
    public int CountVariables() {
        return 1;
    }

    @Override
    public boolean IsOutput() {
        return true;
    }
}
