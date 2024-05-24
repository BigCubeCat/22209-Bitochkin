package org.nsu.gogledoc.Cmd;

public class Cmd {
    public boolean invalid = false;
    public String user;
    public CmdType eType;
    public int position;
    public int size;
    public String content;
    public int unixtime;

    @Override
    public String toString() {
        return ("user=" + user + ";eType=" + eType.toString() +
                ";position=" + position + ";content=" +
                content + ";unixtime=" + unixtime);
    }
}
