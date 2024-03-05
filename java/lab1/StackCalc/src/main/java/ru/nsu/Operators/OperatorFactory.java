package ru.nsu.Operators;

import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;

public class OperatorFactory {
    Map<String, OperatorInterface> map = new HashMap<>();
    Map<String, String> names = new HashMap<>();


    public OperatorFactory() {
        names.put("PRINT", "ru.nsu.Operators.Util.PrintOperator");
        names.put("POP", "ru.nsu.Operators.Util.PopOperator");
        names.put("PUSH", "ru.nsu.Operators.Util.PushOperator");
        names.put("DEFINE", "ru.nsu.Operators.Util.DefineOperator");
        names.put("+", "ru.nsu.Operators.Math.PlusOperator");
        names.put("-", "ru.nsu.Operators.Math.MinusOperator");
        names.put("*", "ru.nsu.Operators.Math.MultOperator");
        names.put("/", "ru.nsu.Operators.Math.DivOperator");
        names.put("SQRT", "ru.nsu.Operators.Math.SqrtOperator");
    }

    public OperatorInterface getCommand(String name) throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
        if (!isLoaded(name)) {
            map.put(name, (OperatorInterface) Class.forName(
                    names.get(name)
            ).getDeclaredConstructor().newInstance());
        }
        return map.get(name);
    }

    boolean isLoaded(String name) {
        return map.containsKey(name);
    }

    public boolean isCommand(String cmd) {
        return names.containsKey(cmd);
    }
}
