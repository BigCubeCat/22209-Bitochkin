#ifndef UNTITLED_RULES_H
#define UNTITLED_RULES_H

#include <iostream>
#include <vector>

struct TRules {
    std::string string;
    std::vector<size_t> birthRule;
    std::vector<size_t> saveRule;

    explicit TRules(const std::string &source);
    explicit TRules(const std::vector<size_t>& b, const std::vector<size_t>& s);
    ~TRules();
};

#endif //UNTITLED_RULES_H
