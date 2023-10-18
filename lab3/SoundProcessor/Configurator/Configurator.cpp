#include "Configurator.h"

#include <iostream>
#include <fstream>

Configurator::~Configurator() = default;

Configurator::Configurator(const std::string &filename) : fileName(filename) {

}

bool Configurator::hasErrors() const {
    return errorsOccurred;
}

void Configurator::run() {
    std::ifstream nameFileout;
    nameFileout.open(fileName);
    std::string line;
    while(std::getline(nameFileout, line))
    {
        std::cout << "line:" << line << std::endl;
    }
}
