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
    Map<String, IAbstractUtilOperator> map = new HashMap<>();

    public OperatorFactory() throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
        map.put("PRINT", (IAbstractUtilOperator) Class.forName(
                "ru.nsu.Operators.Util.PrintOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("POP", (IAbstractUtilOperator) Class.forName(
                "ru.nsu.Operators.Util.PopOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("PUSH", (IAbstractUtilOperator) Class.forName(
                "ru.nsu.Operators.Util.PushOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("DEFINE", (IAbstractUtilOperator) Class.forName(
                "ru.nsu.Operators.Util.DefineOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("+", (IAbstractUtilOperator) Class.forName(
                "ru.nsu.Operators.Util.PlusOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("-", (IAbstractUtilOperator) Class.forName(
                "ru.nsu.Operators.Util.MinusOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("*", (IAbstractUtilOperator) Class.forName(
                "ru.nsu.Operators.Util.MultOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("/", (IAbstractUtilOperator) Class.forName(
                "ru.nsu.Operators.Util.DivOperator"
        ).getDeclaredConstructor().newInstance());

        map.put("SQRT", (IAbstractUtilOperator) Class.forName(
                "ru.nsu.Operators.Util.SqrtOperator"
        ).getDeclaredConstructor().newInstance());

    }

    public boolean isCommand(String cmd) {
        return map.containsKey(cmd);
    }

    public OperatorInterface getCommand(String cmd) {
        return map.get(cmd);
    }
}
