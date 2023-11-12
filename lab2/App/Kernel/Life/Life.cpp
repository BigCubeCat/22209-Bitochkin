#include "Life.h"

Life::Life(size_t w, size_t h)
    : width(w), height(h), neighborhood(TNeighborhood(MOORE)) {
    oldArena = new char[height * width];
    newArena = new char[height * width];
    for (size_t i = 0; i < height * width; ++i) {
        oldArena[i] = 0;
        newArena[i] = 0;
    }
    setRules(TRules("B3/S2,3"));
}

void Life::nextGen() {
    for (size_t row = 0; row < height; ++row) {
        for (size_t col = 0; col < width; ++col) {
            newArena[row * width + col] = newValue(row, col);
        }
    }
    std::swap(newArena, oldArena);
}

char Life::newValue(size_t row, size_t col) {
    auto countNeighbors = calcNeighbors(row, col);
    if (oldArena[row * width + col] == 0) {
        return birthMap[countNeighbors] ? 1 : 0;
    }
    return saveMap[countNeighbors] ? 1 : 0;
}

size_t Life::calcNeighbors(size_t row, size_t col) {
    size_t result = 0;
    for (const auto &coords : neighborhood.points) {
        size_t rowIndex = (height + row + coords.x) % height;
        size_t colIndex = (width + col + coords.y) % width;
        result += oldArena[rowIndex * width + colIndex];
    }
    return result;
}

void Life::toggleCell(int row, int col) {
    oldArena[row * width + col] = 1 - oldArena[row * width + col];
}

void Life::setRules(const TRules &r) {
    rules = r;
    birthMap.clear();
    saveMap.clear();
    for (const auto &value : rules.birthRule) {
        birthMap[value] = true;
    }
    for (const auto &value : rules.saveRule) {
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

std::string Life::getNeighborhood() const {
    std::string result =
        neighborhood.title == MOORE ? "M " : "V ";
    result += std::to_string(neighborhood.degree);
    return result;
}

std::string Life::getRules() const {
    return rules.string;
}

char Life::operator[](int index) {
    return oldArena[index];
}
Life::~Life() {
    free(oldArena);
    free(newArena);
}