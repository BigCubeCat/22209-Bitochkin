#include "StateStorage.h"

#include <iostream>

StateStorage::StateStorage() = default;

StateStorage::~StateStorage() {
}

void StateStorage::updateAll() {
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

std::vector<std::vector<char>> *StateStorage::getArena() {

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
