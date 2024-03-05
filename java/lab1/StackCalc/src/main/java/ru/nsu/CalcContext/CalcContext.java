package ru.nsu.CalcContext;

import ru.nsu.logging.CalcLoggerFinder;

import java.util.HashMap;
import java.util.Stack;

public class CalcContext {

    private final System.Logger logger = CalcLoggerFinder.getLogger("context", this.getClass().getModule());
    private final HashMap<String, Double> map = new HashMap<>();
    private final Stack<Double> values = new Stack<>();
    private Double out;

    public Double Pop() {
        var result = values.pop();
        logger.log(System.Logger.Level.INFO, "pop value: " + result);
        return result;
    }

    public Double Print() {
        logger.log(System.Logger.Level.INFO, "print value");
        return values.lastElement();
    }

    public void Push(Double value) {
        logger.log(System.Logger.Level.INFO, "push value: ", value);
        values.push(value);
    }

    Double ParseDouble(String variable) {
        return Double.parseDouble(variable);
    }

    Double ParseVariable(String variable) {
        if (map.containsKey(variable)) {
            return map.get(variable);
        }
        return null;
    }

    public Double GetVariable(String variable) throws UnknowVariableException {
        logger.log(System.Logger.Level.INFO, "reading variable: ", variable);
        try {
            var result = ParseDouble(variable);
            logger.log(System.Logger.Level.INFO, "number: " + result);
            return result;
        } catch (NumberFormatException nfe) {
            var result = ParseVariable(variable);
            if (result != null) {
                return result;
            } else {
                throw new UnknowVariableException();
            }
        }
    }

    public void SetVariable(String variable, Double value) {
        logger.log(System.Logger.Level.INFO, "setting variable: " + variable + " = " + value);
        map.put(variable, value);
    }

    public void SetOut(Double value) {
        logger.log(System.Logger.Level.INFO, "set output: " + value);
        out = value;
    }

    public Double GetOut() {
        logger.log(System.Logger.Level.INFO, "get output: " + out);
        var result = out;
        out = 0.0;
        return result;
    }
}
