#include <algorithm>
#include "Arena.h"

Arena::Arena(size_t width, size_t height) : width(width), height(height){
    arena = new char[height * width];
    for (size_t i = 0; i < height * width; ++i) {
        arena[i] = 0;
    }
}

char Arena::operator[](size_t index) {
    return arena[index];
}

void Arena::toggleCell(size_t row, size_t col) {
    arena[row * width + col] = arena[row * width + col] == 0 ? 1 : 0;
}

char Arena::getCell(size_t rowIndex, size_t colIndex) {
    return arena[rowIndex * width + colIndex];
}

char *Arena::getArena() {
    return arena;
}

void Arena::setCell(size_t rowIndex, size_t colIndex, char value) {
    arena[rowIndex * width + colIndex] = value;
}
