package ru.nsu.Operators;

import ru.nsu.CalcContext.CalcContext;

public class PopOperator implements AbstractOperator {
    @Override
    public void Exec(CalcContext ctx, String[] args) {
        ctx.SetOut(ctx.Pop());
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
