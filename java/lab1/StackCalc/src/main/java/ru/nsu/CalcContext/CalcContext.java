package ru.nsu.CalcContext;

import java.util.HashMap;
import java.util.Stack;

public class CalcContext {
    private HashMap<String, Double> map;
    private Stack<Double> values;

    public CalcContext() {
    }

    public Double Pop() {
        return values.pop();
    }

    public Double Print() {
        return values.lastElement();
    }

    public void Push(Double value) {
        values.push(value);
    }

    public Double GetVariable(String variable) throws UnknowVariableException {
        try {
            Double num = Double.parseDouble(variable);
            return num;
        } catch (NumberFormatException nfe) {
            if (map.containsKey(variable)) {
                Double num = map.get(variable);
                return num;
            } else {
                throw new UnknowVariableException();
            }
        }
    }

    public void SetVariable(String variable, Double value) {
        map.put(variable, value);
    }
}
