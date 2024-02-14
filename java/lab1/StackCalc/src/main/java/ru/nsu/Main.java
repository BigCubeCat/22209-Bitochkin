package ru.nsu;

import ru.nsu.CmdParser.Parser;

public class Main {
    public static void main(String[] args) {
        Parser view = new Parser();
        view.ExecCommand("# test");
    }
}