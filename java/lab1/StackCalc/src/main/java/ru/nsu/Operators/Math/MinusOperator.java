package ru.nsu.Operators.Math;

public class MinusOperator extends MathOperator {
    public MinusOperator() {
        super(2);
    }

    @Override
    public Double doCalculation(Double[] nums) {
        return nums[0] - nums[1];
    }
}
