#ifndef ARENA_H
#define ARENA_H


class Arena {
public:
    Arena(size_t width, size_t height);
    char operator[](size_t index);
    void toggleCell(size_t width, size_t height);
    char getCell(size_t rowIndex, size_t colIndex);
    void setCell(size_t rowIndex, size_t colIndex, char value);
    char *getArena();
private:
    char *arena;
    size_t width, height;
};

#endif
