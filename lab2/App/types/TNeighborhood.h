#ifndef TNEIGHBORHOOD_H
#define TNEIGHBORHOOD_H

#include <string>
#include <vector>

/*
 * ENeighborhood
 *
 * Moore - (2 * degree + 1) x (2 * degree + 1) rect
 * Von-Neighman - Manhattan distance <= degree
 */
enum ENeighborhood {
    MOORE,
    VON  // MOORE - Соседство Мура, VON - Фон-Неймана
};

struct TNeighborhood {
    /*
     * title
     * Neighborhood
     */
    ENeighborhood title;
    /*
     * degree
     *
     * Degree of neighborhood
     */
    int degree = 1;
    std::vector<std::pair<int, int>> points;

    explicit TNeighborhood(ENeighborhood neigh = MOORE, int deg = 1);
};

#endif
