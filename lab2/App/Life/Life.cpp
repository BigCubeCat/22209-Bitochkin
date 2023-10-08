#include "Life.h"

#include <stdlib.h>

Life::Life(size_t w, size_t h)
        : width(w), height(h),
          neighborhood(TNeighborhood(MOORE)) {
    oldArena = (char *) calloc(height * width, sizeof(char));
    newArena = (char *) calloc(height * width, sizeof(char));
    setRules(TRules("B3/S2,3"));
}

void Life::nextGen() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << (oldArena[i * width + j] ? '#' : '_');
        }
        std::cout << '\n';
    }
    for (size_t row = 0; row < height; ++row) {
        for (size_t col = 0; col < width; ++col) {
            newArena[row * width + col] = newValue(row, col);
        }
    }
    std::swap(newArena, oldArena);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << (oldArena[i * width + j] ? '#' : '_');
        }
        std::cout << '\n';
    }
}

char Life::newValue(size_t row, size_t col) {
    auto countNeighbors = calcNeighbors(row, col);
    if (oldArena[row * width + col] == 0) {
        std::cout << "birthMap[" << countNeighbors << "] = " << birthMap[countNeighbors] << "\n";
        return birthMap[countNeighbors] ? 1 : 0;
    }
    return saveMap[countNeighbors] ? 1 : 0;
}

size_t Life::calcNeighbors(size_t row, size_t col) {
    size_t result = 0;
    for (const auto &coords: neighborhood.points) {
        size_t rowIndex = (height + row + coords.first) % height;
        size_t colIndex = (width + col + coords.second) % width;
        result += oldArena[rowIndex * width + colIndex];
    }
    if (result)
        std::cout << "result = " << result << "\n";
    return result;
}

void Life::toggleCell(size_t row, size_t col) {
    oldArena[row * width + col] = 1 - oldArena[row * width + col];
}

void Life::setRules(const TRules &r) {
    rules = r;
    birthMap.clear();
    saveMap.clear();
    for (const auto &value: rules.birthRule) {
        birthMap[value] = true;
    }
    for (const auto &value: rules.saveRule) {
        saveMap[value] = true;
    }
}

void Life::setNeighborhood(const TNeighborhood &n) {
    neighborhood = n;
}

char *Life::getArena() {
    return oldArena;
}

size_t Life::getWidth() const {
    return width;
}

size_t Life::getHeight() const {
    return height;
}



