#ifndef LIFE_H
#define LIFE_H

#include <map>

#include "../../Kernel/types/TNeighborhood.h"
#include "../../Kernel/types/TRules.h"
#include "Arena.h"

class Life {
   private:
    Arena arena{0, 0};
    Arena newArena{0, 0};

    size_t width;
    size_t height;

    std::map<size_t, bool> birthMap;
    std::map<size_t, bool> saveMap;

    TNeighborhood neighborhood;
    TRules rules;

   public:
    explicit Life(size_t w = 64, size_t h = 64);
    ~Life();

    void toggleCell(size_t row, size_t col);

    void setRules(const TRules &r);

    void setNeighborhood(const TNeighborhood &n);

    Arena &getArena() const;

    void nextGen();

    size_t calcNeighbors(size_t row, size_t col);

    ECellState newValue(size_t row, size_t col);

    std::string getRules() const;

    std::string getNeighborhood() const;
};

#endif
