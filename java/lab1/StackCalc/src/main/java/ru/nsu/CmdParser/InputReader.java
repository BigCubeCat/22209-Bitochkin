package ru.nsu.CmdParser;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class InputReader {
    private final Scanner scanner;
    private boolean isEnd = false;

    public InputReader(String fileName) throws FileNotFoundException {
        scanner = new Scanner(new File(fileName));
    }

    public InputReader() {
        scanner = new Scanner(System.in);
    }

    public String ReadCmd() {
        if (scanner.hasNextLine()) {
            return scanner.nextLine();
        } else {
            isEnd = true;
        }
        return "";
    }

    public boolean IsEnd() {
        return isEnd;
    }

    protected void finalize() {
        scanner.close();
    }
}
