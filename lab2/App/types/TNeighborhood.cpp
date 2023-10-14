#include "TNeighborhood.h"

#include <string>

TNeighborhood::TNeighborhood(ENeighborhood neigh, int deg)
    : title(neigh), degree(deg) {
    for (int i = -deg; i <= deg; ++i) {
        for (int j = -deg; j <= deg; ++j) {
            if (i == 0 && j == 0) continue;
            if (neigh == MOORE) {
                points.emplace_back(i, j);
            } else if (abs(i) + abs(j) <= deg) {  // Пространство Фон-Неймана
                points.emplace_back(i, j);
            }
        }
    }
}
