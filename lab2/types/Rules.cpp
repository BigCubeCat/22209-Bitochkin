#include "Rules.h"

#include <iostream>
#include <string>


TRules::TRules(const std::string &source): string(source) {
    std::string currentNumber;
    int newValue;
    bool isSave = false;
    for (size_t i = 0; i < string.length(); ++i) {
        switch (string[i]) {
            case 'B':
                isSave = false;
                break;
            case 'S':
                isSave = true;
                break;
            case ',':
                newValue = std::stoi(currentNumber);
                if (isSave) {
                    saveRule.push_back(newValue);
                } else {
                    birthRule.push_back(newValue);
                }
                break;
            case '/':
                continue;
            default:
                currentNumber += source[i];
                break;
        }

    }
}

TRules::TRules(const std::vector<size_t>& b, const std::vector<size_t>& s) : birthRule(b), saveRule(s) {
    string = "B";
    for (size_t i = 0; i < birthRule.size(); ++i) {
        string += std::to_string(birthRule[i]);
        string += (i == birthRule.size() - 1) ? '/' : ',';
    }
    string += 'S';
    for (size_t i = 0; i < saveRule.size(); ++i) {
        string += std::to_string(saveRule[i]);
        string += (i == birthRule.size() - 1) ? '\n' : ',';
    }
}

TRules::~TRules() {
    birthRule.clear();
    saveRule.clear();
}
