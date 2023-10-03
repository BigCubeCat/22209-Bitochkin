#ifndef UNTITLED_LIFE_H
#define UNTITLED_LIFE_H

#include <map>

#include "../types/TNeighborhood.h"
#include "../types/TRules.h"


class Life {
private:
    std::vector<std::vector<char>> newArena;
    std::vector<std::vector<char>> oldArena;

    size_t width;
    size_t height;

    std::map<size_t, char> birthMap;
    std::map<size_t, char> saveMap;

    TNeighborhood neighborhood;
    TRules rules;
public:

    explicit Life();

    void setGeometry(size_t countRows, size_t countCols);

    void toggleCell(size_t row, size_t col);

    void setRules(const TRules &r);

    void setNeighborhood(const TNeighborhood &n);

    std::vector<std::vector<char>> *getArena();

    void nextGen();

    size_t calcNeighbors(size_t row, size_t col);
    char newValue(size_t row, size_t col);
};


#endif //UNTITLED_LIFE_H
