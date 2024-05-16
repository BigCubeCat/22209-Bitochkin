package org.nsu.gogledoc.Cmd;

public class Cmd {
    public String user;
    public CmdType eType;
    public int cursor;
    public int end;
    public String content;
    public int unixtime;

    @Override
    public String toString() {
        return ("user=" + user + ";eType=" + eType.toString() +
                ";cursor=" + cursor + ";end=" + end + ";content=" +
                content + ";unixtime=" + unixtime);
    }
}
