package ru.nsu.Operators.Math;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.Operators.OperatorInterface;

abstract class MathOperator implements OperatorInterface {
    int countVariables = 2;

    public MathOperator(int count) {
        countVariables = count;
    }

    public Double doCalculation(Double[] nums) {
        return null;
    }

    @Override
    public void Exec(CalcContext ctx, String[] args) {
        Double[] nums = new Double[CountVariables()];
        for (int i = CountVariables() - 1; i >= 0; --i) {
            nums[i] = ctx.Pop();
        }
        ctx.Push(doCalculation(nums));
    }

    @Override
    public int CountVariables() {
        return countVariables;
    }

    @Override
    public boolean IsOutput() {
        return false;
    }
}
