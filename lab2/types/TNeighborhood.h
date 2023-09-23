#ifndef TNEIGHBORHOOD_H
#define TNEIGHBORHOOD_H

#include <vector>
#include <string>

enum ENeighborhood {
    M, F // M - Соседство Мура, F - Фон-Неймана
};

struct TNeighborhood {
    ENeighborhood title;
    int countPoints = 0;
    int degree = 1;
    std::vector<std::pair<int, int>> points;

    explicit TNeighborhood(ENeighborhood neigh = M, int deg=1);
    std::string string();
};


#endif
