package ru.nsu;

import ru.nsu.CmdParser.InputReader;
import ru.nsu.StackCalc.Translator;

import java.io.FileNotFoundException;
import java.lang.reflect.InvocationTargetException;

public class Main {
    public static void main(String[] args) {
        try {
            InputReader ir;

            if (args.length == 0) {
                ir = new InputReader();
            } else {
                ir = new InputReader(args[0]);
            }

            Translator translator = new Translator(ir);
            translator.Run();

            ir.close();
        } catch (FileNotFoundException e) {
            System.err.println("error: cant open file");
        } catch (ClassNotFoundException e) {
            System.err.println("error: class not found");
        } catch (InvocationTargetException e) {
            System.err.println("error: invocation target");
        } catch (NoSuchMethodException e) {
            System.err.println("error: invalid method");
        } catch (InstantiationException e) {
            System.err.println("error: cant init class");
        } catch (IllegalAccessException e) {
            System.err.println("error: illeagal access");
        }
    }
}