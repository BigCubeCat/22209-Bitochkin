package ru.nsu.Operators;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;

public interface AbstractOperator {
    Double Exec(CalcContext ctx, String[] args) throws InvalidCountVariablesException, UnknowVariableException;
    int CountVariables();
}
