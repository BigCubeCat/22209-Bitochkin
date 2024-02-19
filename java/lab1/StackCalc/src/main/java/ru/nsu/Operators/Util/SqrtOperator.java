package ru.nsu.Operators.Util;

import ru.nsu.Operators.Math.MathOperator;

public class SqrtOperator extends MathOperator {
    public SqrtOperator() {
        super(1);
    }

    @Override
    public Double doCalculation(Double[] nums) {
        return Math.sqrt(nums[0]);
    }
}
