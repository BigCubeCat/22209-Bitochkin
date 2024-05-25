package org.nsu.gogledoc.Cmd;

public enum CmdType {
    REPLACE,
    INSERT, // Заменяем выделенную строку
    DELETE, // Удаляем выделенную строку
    CREATE, // Создать файл
    JUMP, // Переместить курсор
    UPDATE,
    INVALID
}
