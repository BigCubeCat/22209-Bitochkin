package ru.nsu;

import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.CmdParser.InputReader;
import ru.nsu.CmdParser.Parser;
import ru.nsu.Operators.InvalidCountVariablesException;

import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) throws UnknowVariableException, InvalidCountVariablesException, FileNotFoundException {
        Parser view = new Parser();
        InputReader ir = null;

        if (args.length == 0) {
            ir = new InputReader();
        } else {
            ir = new InputReader(args[0]);
        }

        while (!ir.IsEnd()) {
            String command = ir.ReadCmd();
            view.ExecCommand(command);
        }
    }
}