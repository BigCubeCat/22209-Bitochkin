package ru.nsu.statcsv.FileWorker;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class FileWorker {
    private boolean endOfFile = false;

    public FileWorker() {
    }

    public String NextWord(InputStreamReader reader) throws IOException {
        String result = "";
        int t;
        while ((t = reader.read()) != -1) {
            // convert the integer true to character
            char r = (char) t;
            if (Character.isAlphabetic(r) || Character.isDigit(r)) {
                result += r;
            } else {
                return result;
            }
        }
        endOfFile = true;
        return result;
    }

    public Boolean isFileEnd() {
        return endOfFile;
    }


    public void WriteLine(OutputStreamWriter writer, String line) throws IOException {
        writer.write(line);
    }
}
