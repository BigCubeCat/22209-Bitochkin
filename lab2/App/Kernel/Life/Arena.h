#ifndef ARENA_H
#define ARENA_H


enum ECellState {
    DEAD,
    ALIVE
};

class Arena {
public:
    Arena(size_t width, size_t height);

    ECellState operator[](size_t index);

    void toggleCell(size_t width, size_t height);

    ECellState getCell(size_t rowIndex, size_t colIndex);

    void setCell(size_t rowIndex, size_t colIndex, ECellState value);

    bool nonZero() const;

    size_t getWidth() const { return width; }

    size_t getHeight() const { return height; }

private:
    size_t calcIndex(size_t row, size_t col);
    std::vector<ECellState> arena{};
    size_t width, height;
};

#endif
