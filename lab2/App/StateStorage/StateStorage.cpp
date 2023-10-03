#include "StateStorage.h"

#include <iostream>

StateStorage::StateStorage() = default;

StateStorage::~StateStorage() {
}

void StateStorage::updateAll() {
}

void StateStorage::setRules(const std::string &newRules) {
    try {
        life->rules = TRules(newRules);
        arena = life->oldArena;
    } catch (const std::invalid_argument &ex) {
        emit invalidRule();
    }
}

void StateStorage::setNeighborhood(ENeighborhood newNeigh, int degree) {
    life->neighborhood = TNeighborhood(newNeigh, degree);
}

void StateStorage::resizeLife(int countRows, int countCols) {
    if (life)
        life->setGeometry(countRows, countCols);
}

void StateStorage::toggleLife(int row, int col) {
    if (life)
        life->toggleCell(row, col);
}

void StateStorage::InitLife() {
    life = new Life();
}
