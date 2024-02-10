#include <algorithm>
#include <vector>
#include "Arena.h"

Arena::Arena(size_t width, size_t height) : width(width), height(height){
    arena.resize(height * width);
    std::fill(arena.begin(), arena.end(), DEAD);
}

ECellState Arena::operator[](size_t index) {
    return arena[index];
}

void Arena::toggleCell(size_t row, size_t col) {
    arena[calcIndex(row, col)] = arena[calcIndex(row, col)] == DEAD ? ALIVE : DEAD;
}

ECellState Arena::getCell(size_t rowIndex, size_t colIndex) {
    return arena[rowIndex * width + colIndex];
}

void Arena::setCell(size_t rowIndex, size_t colIndex, ECellState value) {
    arena[calcIndex(rowIndex, colIndex)] = value;
}

bool Arena::nonZero() const {
    return width > 0 && height > 0;
}

size_t Arena::calcIndex(size_t row, size_t col) {
    return row * width + col;
}
