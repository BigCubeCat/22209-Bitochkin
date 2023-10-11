#ifndef TRULES_H
#define TRULES_H

#include <vector>
#include <string>

struct TRules {
    /*
     * string
     *
     * String rules pattern, default B3/S2,3
     */
    std::string string;
    /*
     * birthRule
     *
     * vector with values, when value is count neighbors for birth
     */
    std::vector<size_t> birthRule;
    /*
     * saveRule
     *
     * vector with values, when value is count neighbors for keep yourself alive
     */
    std::vector<size_t> saveRule;

    explicit TRules(std::string source = "B2/S2,3");

    explicit TRules(const std::vector<size_t> &b, const std::vector<size_t> &s);
};

#endif
