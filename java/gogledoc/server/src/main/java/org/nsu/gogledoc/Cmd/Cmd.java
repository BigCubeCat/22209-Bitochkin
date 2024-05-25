package org.nsu.gogledoc.Cmd;

public class Cmd {
    public CmdType eType = CmdType.INVALID; // Тип команды
    public String user;  // Ник пользователя
    public int position; // Позиция курсора
    public int size; // Размер выделенной области
    public String content;
    public int unixtime;

    @Override
    public String toString() {
        if (eType != CmdType.INVALID) {
            return ("user=" + user + ";eType=" + eType.toString() +
                    ";position=" + position + ";content=" +
                    content + ";unixtime=" + unixtime);
        }
        return "INVALID";
    }
}
