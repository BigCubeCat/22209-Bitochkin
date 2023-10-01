#include "StateStorage.h"

#include <iostream>

StateStorage::StateStorage() = default;

StateStorage::~StateStorage() {
}

void StateStorage::updateAll() {
}

void StateStorage::setRules(const std::string &newRules) {
    try {
        rules = new TRules(newRules);
    } catch (const std::invalid_argument &ex) {
        emit invalidRule();
    }
}

void StateStorage::setNeighborhood(ENeighborhood newNeigh, int degree) {
    neighborhood = new TNeighborhood(newNeigh, degree);
}

void StateStorage::testSlot() {
    std::cout << "hi from test slot\n";
}
