package ru.nsu;

import ru.nsu.CmdParser.InputReader;
import ru.nsu.StackCalc.Translator;

import java.io.FileNotFoundException;
import java.lang.reflect.InvocationTargetException;

public class Main {
    public static void main(String[] args) throws FileNotFoundException, ClassNotFoundException, InvocationTargetException, NoSuchMethodException, InstantiationException, IllegalAccessException {
        InputReader ir;

        if (args.length == 0) {
            ir = new InputReader();
        } else {
            ir = new InputReader(args[0]);
        }

        Translator translator = new Translator(ir);
        translator.Run();
    }
}