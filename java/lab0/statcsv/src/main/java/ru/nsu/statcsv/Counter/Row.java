package ru.nsu.statcsv.Counter;

public class Row {
    public String Title;
    public Integer Count;
    public Float Percent;

    public Row(String title, Integer count, Float percent) {
        Title = title;
        Count = count;
        Percent = percent;
    }

    public String toString() {
        return Title + ',' + Count + ',' + Percent;
    }
}
