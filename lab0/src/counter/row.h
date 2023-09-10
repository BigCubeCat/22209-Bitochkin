#pragma once

#include <string>

struct Row {
    std::string word;
    int count;
    float frequency;

    bool operator<(Row& other);
};
