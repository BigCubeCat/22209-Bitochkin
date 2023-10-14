#ifndef UNTITLED_LIFE_H
#define UNTITLED_LIFE_H

#include <QString>
#include <map>

#include "../types/TNeighborhood.h"
#include "../types/TRules.h"

class Life {
   private:
    char *newArena{};
    char *oldArena{};

    size_t width;
    size_t height;

    std::map<size_t, bool> birthMap;
    std::map<size_t, bool> saveMap;

    TNeighborhood neighborhood;
    TRules rules;

   public:
    explicit Life(size_t w = 64, size_t h = 64);

    void toggleCell(int row, int col);

    void setRules(const TRules &r);

    void setNeighborhood(const TNeighborhood &n);

    char *getArena();

    void nextGen();

    size_t getWidth() const;

    size_t getHeight() const;

    size_t calcNeighbors(size_t row, size_t col);

    char newValue(size_t row, size_t col);

    QString getRules() const;

    QString getNeighborhood() const;

    char operator[](int index);
};

#endif
