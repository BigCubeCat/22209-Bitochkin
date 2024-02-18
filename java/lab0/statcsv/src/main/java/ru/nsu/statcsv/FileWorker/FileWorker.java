package ru.nsu.statcsv.FileWorker;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class FileWorker {
    private boolean endOfFile = false;

    public String NextWord(InputStreamReader reader) throws IOException {
        String result = "";
        int symbol;
        while ((symbol = reader.read()) != -1) {
            char ch = (char) symbol;
            if (Character.isAlphabetic(ch) || Character.isDigit(ch)) {
                result += ch;
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
