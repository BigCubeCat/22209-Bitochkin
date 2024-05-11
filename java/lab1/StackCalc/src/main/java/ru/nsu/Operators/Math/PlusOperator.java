package ru.nsu.Operators.Math;

public class PlusOperator extends MathOperator {
    public PlusOperator() {
        super(2);
    }

    @Override
    public Double doCalculation(Double[] nums) {
        return nums[0] + nums[1];
    }
}
