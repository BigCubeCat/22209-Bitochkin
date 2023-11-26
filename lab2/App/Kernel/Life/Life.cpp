#include "Life.h"

Life::Life(size_t w, size_t h)
        : width(w), height(h), neighborhood(TNeighborhood(MOORE)) {
    arena = Arena(w, h);
    newArena = Arena(w, h);
    setRules(TRules("B3/S2,3"));
}

void Life::nextGen() {
    for (size_t row = 0; row < height; ++row) {
        for (size_t col = 0; col < width; ++col) {
            newArena.setCell(row, col, newValue(row, col));
        }
    }
    std::swap(arena, newArena);
}

ECellState Life::newValue(size_t row, size_t col) {
    auto countNeighbors = calcNeighbors(row, col);
    if (arena.getCell(row, col) == DEAD) {
        return birthMap[countNeighbors] ? ALIVE : DEAD;
    }
    return saveMap[countNeighbors] ? ALIVE : DEAD;
}

size_t Life::calcNeighbors(size_t row, size_t col) {
    size_t result = 0;
    for (const auto &coords: neighborhood.points) {
        size_t rowIndex = (height + row + coords.x) % height;
        size_t colIndex = (width + col + coords.y) % width;
        result += arena.getCell(rowIndex, colIndex);
    }
    return result;
}

void Life::toggleCell(size_t row, size_t col) {
    arena.toggleCell(row, col);
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

Arena *Life::getArena() {
    return &arena;
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

ECellState Life::operator[](size_t index) {
    return arena[index];
}

Life::~Life() {
}
