package ru.nsu.Operators.Util;

import ru.nsu.CalcContext.CalcContext;

public class PrintOperator implements IAbstractUtilOperator {
    @Override
    public void Exec(CalcContext ctx, String[] args) {
        ctx.SetOut(ctx.Print());
    }

    @Override
    public int CountVariables() {
        return 0;
    }

    @Override
    public boolean IsOutput() {
        return true;
    }
}
