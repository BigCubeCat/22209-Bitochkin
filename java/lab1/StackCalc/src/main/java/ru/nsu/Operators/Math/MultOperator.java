package ru.nsu.Operators.Math;

public class MultOperator extends MathOperator {
    public MultOperator() {
        super(2);
    }

    @Override
    public Double doCalculation(Double[] nums) {
        return nums[0] * nums[1];
    }
}
