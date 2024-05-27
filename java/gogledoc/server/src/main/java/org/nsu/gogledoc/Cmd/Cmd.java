package org.nsu.gogledoc.Cmd;

public class Cmd {
    public CmdType eType = CmdType.INVALID; // Тип команды
    public String user;  // Ник пользователя
    public int begin; // Позиция курсора
    public int end; // Размер выделенной области
    public String content;
    public int unixtime = 0;
}
