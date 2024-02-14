package ru.nsu.Operators;

import ru.nsu.CalcContext.CalcContext;

public class PrintOperator implements AbstractOperator {
    @Override
    public Double Exec(CalcContext ctx, String[] args) {
        return ctx.Print();
    }

    @Override
    public int CountVariables() {
        return 0;
    }
}
