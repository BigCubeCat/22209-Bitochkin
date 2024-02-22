package ru.nsu.Operators;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.Operators.Exceptions.InvalidCountVariablesException;
import ru.nsu.Operators.Math.*;
import ru.nsu.Operators.Util.*;

import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;

public class OperatorFactory {
    Map<String, OperatorInterface> map = new HashMap<>();

    public OperatorFactory() throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
        map.put("PRINT", (OperatorInterface) Class.forName(
                "ru.nsu.Operators.Util.PrintOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("POP", (OperatorInterface) Class.forName(
                "ru.nsu.Operators.Util.PopOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("PUSH", (OperatorInterface) Class.forName(
                "ru.nsu.Operators.Util.PushOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("DEFINE", (OperatorInterface) Class.forName(
                "ru.nsu.Operators.Util.DefineOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("+", (OperatorInterface) Class.forName(
                "ru.nsu.Operators.Math.PlusOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("-", (OperatorInterface) Class.forName(
                "ru.nsu.Operators.Math.MinusOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("*", (OperatorInterface) Class.forName(
                "ru.nsu.Operators.Math.MultOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("/", (OperatorInterface) Class.forName(
                "ru.nsu.Operators.Math.DivOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("SQRT", (OperatorInterface) Class.forName(
                "ru.nsu.Operators.Math.SqrtOperator"
        ).getDeclaredConstructor().newInstance());

    }

    public boolean isCommand(String cmd) {
        return map.containsKey(cmd);
    }

    public OperatorInterface getCommand(String cmd) {
        return map.get(cmd);
    }
}
