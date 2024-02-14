package ru.nsu.Operators;

import ru.nsu.CalcContext.CalcContext;

public class PopOperator implements AbstractOperator {
    @Override
    public Double Exec(CalcContext ctx, String[] args) {
        return ctx.Pop();
    }

    @Override
    public int CountVariables() {
        return 1;
    }
}
