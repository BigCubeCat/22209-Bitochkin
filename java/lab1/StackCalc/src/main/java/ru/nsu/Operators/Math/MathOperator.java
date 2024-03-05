package ru.nsu.Operators.Math;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.Operators.Exceptions.InvalidCountVariablesException;

abstract class MathOperator implements IMathAbstractOperator {
    int countVariables = 2;

    public MathOperator(int count) {
        countVariables = count;
    }

    public Double doCalculation(Double[] nums) {
        return null;
    }

    @Override
    public void Exec(CalcContext ctx, String[] args) throws InvalidCountVariablesException, UnknowVariableException {
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
