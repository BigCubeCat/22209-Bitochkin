#include "Life.h"

Life::Life()
        : width(64), height(64),
          neighborhood(TNeighborhood(MOORE)), rules(TRules("B3/S2,3")) {
}

void Life::nextGen() {
    for (size_t row = 0; row < height; ++row) {
        for (size_t col = 0; col < width; ++col) {
            newArena[row][col] = newValue(row, col);
        }
    }
    newArena.swap(oldArena);
}

char Life::newValue(size_t row, size_t col) {
    auto countNeighbors = calcNeighbors(row, col);
    if (oldArena[row][col]) {
        return birthMap[countNeighbors];
    }
    return saveMap[countNeighbors];
}

size_t Life::calcNeighbors(size_t row, size_t col) {
    size_t result = 0;
    for (const auto &coords: neighborhood.points) {
        result += oldArena[
                (height + row + coords.first) % height
        ][
                (width + col + coords.second) % width
        ];
    }
    return result;
}

void Life::setGeometry(size_t countRows, size_t countCols) {
    oldArena.resize(countRows);
    newArena.resize(countRows);
    for (size_t i = 0; i < countRows; ++i) {
        oldArena[i].resize(countCols);
        newArena[i].resize(countCols);
    }
}

void Life::toggleCell(size_t row, size_t col) {
    oldArena[row][col] = 1;
}

void Life::setRules(const TRules &r) {
    rules = r;
}

void Life::setNeighborhood(const TNeighborhood &n) {
    neighborhood = n;
}

std::vector<std::vector<char>> *Life::getArena() {
    return &oldArena;
}



