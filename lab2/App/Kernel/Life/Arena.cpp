#include <algorithm>
#include <vector>
#include "Arena.h"

Arena::Arena(size_t width, size_t height) : width(width), height(height){
    arena.resize(height * width);
    for (size_t i = 0; i < height * width; ++i) {
        arena[i] = DEAD;
    }
}

ECellState Arena::operator[](size_t index) {
    return arena[index];
}

void Arena::toggleCell(size_t row, size_t col) {
    arena[row * width + col] = arena[row * width + col] == DEAD ? ALIVE : DEAD;
}

ECellState Arena::getCell(size_t rowIndex, size_t colIndex) {
    return arena[rowIndex * width + colIndex];
}

void Arena::setCell(size_t rowIndex, size_t colIndex, ECellState value) {
    arena[rowIndex * width + colIndex] = value;
}
