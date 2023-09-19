#ifndef GAMEARENA_H
#define GAMEARENA_H

#include <bitset>

#include "../../types/TNeighborhood.h"
#include "../../types/TRules.h"


class GameArena {
private:
    TNeighborhood neighborhood;
    TRules rules;
    std::vector<int> oldArena;
    std::vector<int> newArena;
    std::vector<int> rulesMap;
    int width;
    int height;
public:
    explicit GameArena(TNeighborhood n, const TRules &r, int w, int h);

    void nextGen(int n = 0);

    int getWidth() const;

    int getHeight() const;
};


#endif
