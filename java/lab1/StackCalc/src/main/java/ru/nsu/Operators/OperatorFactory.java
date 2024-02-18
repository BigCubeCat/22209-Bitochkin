package ru.nsu.Operators;

import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;

public class OperatorFactory {
    Map<String, Function<String[], AbstractOperator>> map;

    public OperatorFactory() {
        map = new HashMap<>();
        map.put("PRINT", args -> new PrintOperator());
        map.put("POP", args -> new PopOperator());
        map.put("PUSH", args -> new PushOperator());
        map.put("DEFINE", args -> new DefineOperator());

        map.put("+", args -> new MathOperator(values -> values[0] + values[1], 2));
        map.put("-", args -> new MathOperator(values -> values[0] - values[1], 2));
        map.put("*", args -> new MathOperator(values -> values[0] * values[1], 2));
        map.put("/", args -> new MathOperator(values -> values[0] / values[1], 2));

        map.put("SQRT", args -> new MathOperator(values -> Math.sqrt(values[0]), 1));
    }

    public boolean isCommand(String cmd) {
        return map.containsKey(cmd);
    }

    public AbstractOperator getCommand(String cmd, String[] args) {
       return map.get(cmd).apply(args);
    }
}
