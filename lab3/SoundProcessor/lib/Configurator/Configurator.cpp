#include "Configurator.h"

#include <fstream>
#include <sstream>
#include <iostream>

Configurator::~Configurator() = default;

Configurator::Configurator(
        const std::string &configFile, const std::string &outFile,
        const std::vector<std::string> &inputFiles
) : input(inputFiles), config(configFile), out(outFile) {
    parse();
}

bool Configurator::hasErrors() const {
    return errorsOccurred;
}

void Configurator::parse() {
    std::ifstream file;
    file.open(config);
    std::string line;
    int i = 1;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
        parseConfigLine(line, i);
        ++i;
    }
}

void Configurator::parseConfigLine(const std::string &line, int lineNumber) {
    std::vector<std::string> cmd = splitLine(line);
    if (cmd.empty()) {
        return;
    }
    if (cmd[0][0] == '#') {
        return;
    }
    if (!isConvertorName(cmd[0])) {
        errorsOccurred = true;
        errorMessage += std::to_string(lineNumber) + ": Invalid command: " + line + "\n";
    } else if (commandIsValid(cmd)) {
        auto conf = ConverterConfig{cmd[0], cmd};
        algorithm.push_back(conf);
    } else {
        errorsOccurred = true;
        errorMessage += std::to_string(lineNumber) + ": Invalid convertor arguments: " + line + "\n";
    }
}

std::vector<std::string> Configurator::splitLine(const std::string &line) {
    std::vector<std::string> result;
    std::string s;
    std::stringstream ss(line);
    std::vector<std::string> v;

    while (getline(ss, s, ' ')) {
        if (!s.empty()) {
            result.push_back(s);
        }
    }
    return result;
}

bool Configurator::isConvertorName(const std::string &name) {
    return commandSet.contains(name);
}

bool Configurator::commandIsValid(const std::vector<std::string> &cmd) {
    if (cmd[0] == "mix") {
        if (cmd.size() == 3) {
            if (linkIsValid(cmd[1]) && isNumber(cmd[2])) {
                return true;
            }
        }
    } else if (cmd[0] == "mute" || cmd[0] == "crop" || cmd[0] == "cut") {
        if (cmd.size() == 3) {
            if (isNumber(cmd[1]) && isNumber(cmd[2])) {
                return true;
            }
        }
    } else if (cmd[0] == "noise") {
        if (cmd.size() == 4) {
            if (isNumber(cmd[1]) && isNumber(cmd[2]) && isNumber(cmd[3])) {
                return true;
            }
        }
    }
    return false;
}

std::vector<ConverterConfig> Configurator::getAlgorithm() {
    return algorithm;
}

bool Configurator::linkIsValid(const std::string &link) {
    if (link[0] == '$') {
        for (int i = 1; i < link.size(); ++i) {
            if (link[i] < '0' | link[i] > '9') {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Configurator::isNumber(const std::string &num) {
    for (int i = 1; i < num.size(); ++i) {
        if (num[i] < '0' | num[i] > '9') {
            return false;
        }
    }
    return true;
}

std::string Configurator::errors() const {
    return errorMessage;
}

