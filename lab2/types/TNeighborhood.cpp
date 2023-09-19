#include "TNeighborhood.h"

#include <string>

std::string TNeighborhood::string() {
    std::string name = (title == M) ? "Мура" : "Фон-Неймана";
    std::string d = std::to_string(degree);
    return "Соседство " + name + " " + d + " степени";
}

TNeighborhood::TNeighborhood(ENeighborhood neigh, int deg) : title(neigh), degree(deg) {
    countPoints = (deg * 2 + 1);
    countPoints *= countPoints;
    for (int i = -deg; i <= deg; ++i) {
        for (int j = -deg; j <= deg; ++j) {
            if (i == 0 && j == 0) continue;
            if (neigh == M) {
                points.push_back({i, j});
            } else if (abs(i) + abs(j) <= deg) { // Пространство Фон-Неймана
                points.push_back({i, j});
            }
        }
    }
}
