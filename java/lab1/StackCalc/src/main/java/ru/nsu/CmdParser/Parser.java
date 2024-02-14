package ru.nsu.CmdParser;


public class Parser {
    public Parser() {
    }

    public void ExecCommand(String command) {
        String[] args = command.split(" ");
        if (args.length == 0) {
            return;
        } else if (args[0] == "#") {
            return;
        }
    }
}
