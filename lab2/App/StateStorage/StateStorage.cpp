#include "StateStorage.h"

#include <iostream>

StateStorage::StateStorage() = default;

StateStorage::~StateStorage() {
    delete life;
    delete rules;
    delete neighborhood;
}

void StateStorage::updateAll() {
}

void StateStorage::setRules(const std::string &newRules) {
    std::cout <<"new Rules = " << newRules << std::endl;
    rules = new TRules(newRules);
}

void StateStorage::setNeighborhood(ENeighborhood newNeigh, int degree) {
    neighborhood = new TNeighborhood(newNeigh, degree);
}

void StateStorage::testSlot() {
    std::cout << "hi from test slot\n";
}
