#ifndef UNTITLED_LIFE_H
#define UNTITLED_LIFE_H

#include <map>

#include "../types/TNeighborhood.h"
#include "../types/TRules.h"


class Life {
private:
    TNeighborhood neighborhood;
    TRules rules;

    std::vector<std::vector<char>> oldArena;
    std::vector<std::vector<char>> newArena;

    size_t width;
    size_t height;

    std::map<size_t, char> birthMap;
    std::map<size_t, char> saveMap;

public:
    explicit Life(TNeighborhood n, const TRules &r, size_t w, size_t h);

    void nextGen();

    size_t getWidth() const;

    size_t getHeight() const;

    char operator[] (size_t index);
    size_t calcNeighbors(size_t row, size_t col);
    char newValue(size_t row, size_t col);
};


#endif //UNTITLED_LIFE_H
