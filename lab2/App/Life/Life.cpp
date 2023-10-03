#include "Life.h"

Life::Life(TNeighborhood n, const TRules &r, size_t w, size_t h) :
        width(w), height(h), rules(r), neighborhood(std::move(n)) {
    oldArena.resize(height);
    newArena.resize(height);
    for (size_t i = 0; i < height; ++i) {
        std::vector<char> oldRow(width, 0);
        std::vector<char> newRow(width, 0);
        oldArena[i] = oldRow;
        newArena[i] = newRow;
    }
}

Life::Life()
        : width(128), height(128),
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

size_t Life::getWidth() const {
    return width;
}

size_t Life::getHeight() const {
    return height;
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
    std::cout << "geometry = " << countRows << " " << countCols << "\n";
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



