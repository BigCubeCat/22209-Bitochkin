package ru.nsu.statcsv;

import ru.nsu.statcsv.Counter.Counter;
import ru.nsu.statcsv.Counter.Row;
import ru.nsu.statcsv.FileWorker.FileWorker;

import java.io.*;

public class App {

    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("No input file");
            return;
        } else if (args.length == 1) {
            System.err.println("No output file");
            return;
        }

        Counter counter = new Counter();
        FileWorker fw = new FileWorker();

        try {
            FileInputStream fis = new FileInputStream(args[0]);
            InputStreamReader reader = new InputStreamReader(fis);

            String word;
            do {
                word = fw.NextWord(reader);
                counter.AddWord(word);
            } while (word != "");
            counter.UpdateRows();
            Row[] rows = counter.getRows();
            for (int i = counter.CountUnique() - 1; i >= 0; --i) {
                System.out.println(rows[i].toString());
            }

            reader.close();
            fis.close();
        } catch (FileNotFoundException e) {
            System.out.println("404: " + e);
        } catch (IOException e) {
            System.out.println("error: " + e);
        }
    }
}
