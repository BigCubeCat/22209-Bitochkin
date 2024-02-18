package ru.nsu;

import ru.nsu.CmdParser.InputReader;
import ru.nsu.CmdParser.Parser;

import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
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