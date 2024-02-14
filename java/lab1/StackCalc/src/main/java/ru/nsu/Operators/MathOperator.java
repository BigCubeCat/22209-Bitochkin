package ru.nsu.Operators;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;

import java.util.function.Function;

public class MathOperator implements AbstractOperator {
    int countVariables = 2;
    Function<Double[], Double> mathOperation;

    public MathOperator(Function<Double[], Double> cmd, int count) {
        mathOperation = cmd;
        countVariables = count;
    }

    @Override
    public void Exec(CalcContext ctx, String[] args) throws InvalidCountVariablesException, UnknowVariableException {
        Double[] nums = new Double[CountVariables()];
        for (int i = CountVariables() - 1; i >= 0; --i) {
            nums[i] = ctx.Pop();
        }
        ctx.Push(mathOperation.apply(nums));
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
