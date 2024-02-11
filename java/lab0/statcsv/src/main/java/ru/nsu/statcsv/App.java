package ru.nsu.statcsv;

import ru.nsu.statcsv.Counter.Counter;
import ru.nsu.statcsv.Counter.Row;
import ru.nsu.statcsv.FileWorker.FileWorker;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

public class App {

    public static void main(String[] args) {
        String sep = ",";
        String end = "\n";
        if (args.length == 0) {
            System.err.println("No input file");
            return;
        } else if (args.length == 1) {
            System.err.println("No output file");
            return;
        } else if (args.length > 2) {
            sep = args[2];
        }
        if (args.length == 4) {
            end = args[3];
        }

        Counter counter = new Counter();
        FileWorker fw = new FileWorker();

        try {
            FileInputStream fis = new FileInputStream(args[0]);
            InputStreamReader reader = new InputStreamReader(fis);

            while (!fw.isFileEnd()) {
                counter.AddWord(fw.NextWord(reader));
            }

            reader.close();
            fis.close();

            counter.UpdateRows();
            Row[] rows = counter.getRows();
            try (OutputStreamWriter writer = new OutputStreamWriter(Files.newOutputStream(Paths.get(args[1])), StandardCharsets.UTF_8)) {
                for (int i = counter.CountUnique() - 1; i >= 0; --i) {
                    fw.WriteLine(writer, rows[i].toString(sep, end));
                }
            } catch (IOException e) {
                System.err.println("error: write failed: " + e.getMessage());
            }


        } catch (FileNotFoundException e) {
            System.out.println("404: " + e);
        } catch (IOException e) {
            System.out.println("error: " + e);
        }
    }
}
