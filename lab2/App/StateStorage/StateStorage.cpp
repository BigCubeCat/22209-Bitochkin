#include "StateStorage.h"

#include <iostream>

StateStorage::StateStorage() = default;

StateStorage::~StateStorage() {
}

void StateStorage::setRules(const std::string &newRules) {
    try {
        life->setRules(TRules(newRules));
    } catch (const std::invalid_argument &ex) {
        emit invalidRule();
    }
}

void StateStorage::setNeighborhood(ENeighborhood newNeigh, int degree) {
    life->setNeighborhood(TNeighborhood(newNeigh, degree));
}

void StateStorage::toggleLife(int row, int col) {
    std::cout << "toggle " << row << " " << col << "\n";
    if (life)
        life->toggleCell(row, col);
}

void StateStorage::InitLife(int countRows, int countCols) {
    arenaHeight = countRows;
    arenaWidth = countCols;
    life = new Life(arenaWidth, arenaHeight);
}

char *StateStorage::getArena() {
    if (life) {
        auto answer = life->getArena();
        if (answer) {
            return answer;
        } else {
            std::cout << "shit\n";
        }
    }
    return nullptr;
}

size_t StateStorage::getWidth() const {
    return life->getWidth();
}

size_t StateStorage::getHeight() const {
    return life->getHeight();
}
