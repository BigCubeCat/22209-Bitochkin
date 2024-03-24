package ru.nsu.Operators;

import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.Operators.Exceptions.InvalidCountVariablesException;

public interface OperatorInterface {
    void Exec(CalcContext ctx, String[] args) throws InvalidCountVariablesException, UnknowVariableException;
    int CountVariables();

    boolean IsOutput();
}
