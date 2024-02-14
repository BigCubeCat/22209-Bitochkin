package ru.nsu.CmdParser;


import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.Operators.InvalidCountVariablesException;
import ru.nsu.StackCalc.StackCalc;

public class Parser {
    public StackCalc calc;

    public Parser() {
        calc = new StackCalc();
    }

    public void ExecCommand(String command) throws UnknowVariableException, InvalidCountVariablesException {
        String[] args = command.split(" ");
        if (args.length == 0) {
            return;
        } else if (args[0] == "#") {
            return;
        }
        calc.RunCommand(args);
    }
}
