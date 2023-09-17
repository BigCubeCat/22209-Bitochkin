#ifndef TNEIGHBORHOOD_H
#define TNEIGHBORHOOD_H


#include <iostream>
#include <vector>

enum ENeighborhood {
    M, F // M - Соседство Мура, F - Фон-Неймана
};

struct TNeighborhood {
    ENeighborhood title;
    std::basic_string<char> degree = 1;
    std::vector<std::pair<int, int>> points;
    explicit TNeighborhood(ENeighborhood neigh, int deg=1);
    std::string string();
    void genVonNeighman();
    void genMoore();
};


#endif
