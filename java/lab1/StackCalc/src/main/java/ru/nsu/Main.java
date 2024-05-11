package ru.nsu;

import ru.nsu.CmdParser.InputReader;
import ru.nsu.StackCalc.Translator;

import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.InvocationTargetException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
            Scanner scanner;

            if (args.length == 0) {
                scanner = new Scanner(System.in);
            } else {
                scanner = new Scanner(new File(args[0]));
            }

            InputReader ir = new InputReader(scanner);
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