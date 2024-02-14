package ru.nsu.Operators;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;

public interface AbstractOperator {
    void Exec(CalcContext ctx, String[] args) throws InvalidCountVariablesException, UnknowVariableException;
    int CountVariables();

    boolean IsOutput();
}
