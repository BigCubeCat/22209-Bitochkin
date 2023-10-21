#include "Configurator.h"

#include <fstream>
#include <sstream>

Configurator::~Configurator() = default;

Configurator::Configurator(const std::string &filename) : fileName(filename) {

}

bool Configurator::hasErrors() const {
    return errorsOccurred;
}

void Configurator::parse() {
    std::ifstream nameFileout;
    nameFileout.open(fileName);
    std::string line;
    while (std::getline(nameFileout, line)) {
        parseConfigLine(line);
    }
}

void Configurator::run() {
    parse();
    if (!errorsOccurred) {

    }
}

void Configurator::parseConfigLine(const std::string &line) {
    auto cmd = splitLine(line);
    if (cmd.empty()) {
        return;
    }
    if (cmd[0] == "#") {
        return;
    }
    if (!isConvertorName(cmd[0])) {
        errorsOccurred = true;
        errorMessage += "Invalid command: " + line + "\n";
    }
}

std::vector<std::string> Configurator::splitLine(const std::string &line) {
    std::vector<std::string> result;
    std::string s;
    std::stringstream ss(line);
    std::vector<std::string> v;

    while (getline(ss, s, ' ')) {
        result.push_back(s);
    }
    return result;
}

bool Configurator::isConvertorName(const std::string &name) {
    return name == "mix" || name == "mute" || name == "reverb";
}

bool Configurator::commandIsValid(const std::vector<std::string> &cmd) {
    if (cmd[0] == "mix") {

    }
}


