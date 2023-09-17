#include "TNeighborhood.h"

std::string TNeighborhood::string() {
    std::string name = (title == M) ? "Мура" : "Фон-Неймана";
    std::string deg = std::stoi(degree);
    return "Соседство " + name + " " + deg + " степени";
}

TNeighborhood::TNeighborhood(ENeighborhood neigh, int deg) : title(neigh), degree(deg) {
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
