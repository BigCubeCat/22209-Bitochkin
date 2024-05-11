package ru.nsu.CmdParser;

import ru.nsu.logging.CalcLoggerFinder;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class InputReader {
    private final Scanner scanner;
    private boolean isEnd = false;
    private final System.Logger logger = CalcLoggerFinder.getLogger("input", this.getClass().getModule());

    public InputReader(Scanner sc) {
        scanner = sc;
    }

    public String ReadCmd() {
        logger.log(System.Logger.Level.INFO, "reading command");
        if (scanner.hasNextLine()) {
            return scanner.nextLine();
        }
        logger.log(System.Logger.Level.WARNING, "end of file");
        isEnd = true;
        return "";
    }

    public boolean IsEnd() {
        return isEnd;
    }

    public void close() {
        scanner.close();
    }
}
