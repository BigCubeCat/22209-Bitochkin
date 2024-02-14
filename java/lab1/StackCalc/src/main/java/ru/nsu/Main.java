package ru.nsu;

import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.CmdParser.Parser;
import ru.nsu.Operators.InvalidCountVariablesException;

public class Main {
    public static void main(String[] args) throws UnknowVariableException, InvalidCountVariablesException {
        Parser view = new Parser();
        view.ExecCommand("DEFINE a 4");
        view.ExecCommand("PUSH a");
        view.ExecCommand("PUSH 5");
        view.ExecCommand("+");
        view.ExecCommand("PRINT");
        view.ExecCommand("SQRT");
        view.ExecCommand("POP");
    }
}