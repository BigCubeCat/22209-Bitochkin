#include "TRules.h"

#include <string>
#include <utility>


TRules::TRules(std::string source): string(std::move(source)) {
    std::string currentNumber;
    int newValue;
    bool isSave = false;
    for (char ch : string) {
        switch (ch) {
            case 'B':
                isSave = false;
                break;
            case 'S':
                isSave = true;
                break;
            case ',':
            case '/':
                newValue = std::stoi(currentNumber);
                if (isSave) {
                    saveRule.push_back(newValue);
                } else {
                    birthRule.push_back(newValue);
                }
                currentNumber = "";
                break;
            default:
                currentNumber += ch;
                break;
        }
    }
    newValue = std::stoi(currentNumber);
    if (isSave) {
        saveRule.push_back(newValue);
    } else {
        birthRule.push_back(newValue);
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
