package ru.nsu.Operators;

import ru.nsu.Operators.Math.*;
import ru.nsu.Operators.Util.*;

import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;

public class OperatorFactory {
    Map<String, Function<String[], OperatorInterface>> map;

    public OperatorFactory() {
        map = new HashMap<>();
        map.put("PRINT", args -> new PrintOperator());
        map.put("POP", args -> new PopOperator());
        map.put("PUSH", args -> new PushOperator());
        map.put("DEFINE", args -> new DefineOperator());

        map.put("+", args -> new PlusOperator());
        map.put("-", args -> new MinusOperator());
        map.put("*", args -> new MultOperator());
        map.put("/", args -> new DivOperator());

        map.put("SQRT", args -> new SqrtOperator());
    }

    public boolean isCommand(String cmd) {
        return map.containsKey(cmd);
    }

    public OperatorInterface getCommand(String cmd, String[] args) {
       return map.get(cmd).apply(args);
    }
}
