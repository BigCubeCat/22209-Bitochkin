package ru.nsu.CmdParser;

import ru.nsu.logging.CalcLoggerFinder;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class InputReader implements AutoCloseable {
    private final Scanner scanner;
    private boolean isEnd = false;
    private final System.Logger logger = CalcLoggerFinder.getLogger("input", this.getClass().getModule());

    public InputReader(String fileName) throws FileNotFoundException {
        logger.log(System.Logger.Level.INFO, "setup scanner");
        scanner = new Scanner(new File(fileName));
        logger.log(System.Logger.Level.INFO, "ok");
    }

    public InputReader() {
        logger.log(System.Logger.Level.INFO, "setup stdin");
        scanner = new Scanner(System.in);
        logger.log(System.Logger.Level.INFO, "ok");
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

    @Override
    public void close() throws Exception {
        scanner.close();
    }
}
