package ru.nsu.Operators.Math;

public class DivOperator extends MathOperator {
    public DivOperator() {
        super(2);
    }

    @Override
    public Double doCalculation(Double[] nums) {
        return nums[0] / nums[1];
    }
}
