package ru.nsu.statcsv.Counter;

import java.util.*;

public class Counter {
    private final Map<String, Integer> data;
    private Row[] rows;
    private Integer totalCount = 0;

    public Counter() {
        data = new HashMap<String, Integer>();
    }

    public void AddWord(String word) {
        if (data.containsKey(word)) {
            data.put(word, data.get(word) + 1);
        } else {
            totalCount++;
            data.put(word, 1);
        }
    }

    public void UpdateRows() {
        rows = new Row[totalCount];
        int index = 0;
        for (Map.Entry<String, Integer> row : data.entrySet()) {
            Integer value = row.getValue();
            rows[index] = new Row(row.getKey(), value, (float) value / totalCount);
            index++;
        }
        //Arrays.sort(rows, Comparator.comparing(p -> p.Count));
    }

    public Map<String, Integer> getData() {
        return data;
    }

    public int CountUnique() {
        return totalCount;
    }

    public Row[] getRows() {
        return rows;
    }
}
