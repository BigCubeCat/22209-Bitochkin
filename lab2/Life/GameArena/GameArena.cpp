#include "GameArena.h"

#include <utility>

namespace {
    const int two_degs[30] = {
            1,
            2,
            4,
            8,
            16,
            32,
            64,
            128,
            256,
            512,
            1024,
            2048,
            4096,
            8192,
            16384,
            32768,
            65536,
            131072,
            262144,
            524288,
            1048576,
            2097152,
            4194304,
            8388608,
            16777216,
            33554432,
            67108864,
            134217728,
            268435456,
            536870912,
            1073741824,
    }
}

void GameArena::nextGen(int n) {
    oldArena.swap(newArena);
}

GameArena::GameArena(TNeighborhood n, const TRules &r, int w, int h) :
        neighborhood(std::move(n)), rules(r), width(w), height(h) {
    oldArena.resize(w * h, 0);
    newArena.resize(w * h, 0);
    rulesMap.resize(neighborhood.countPoints, 0);
}

int GameArena::getWidth() const {
    return width;
}

int GameArena::getHeight() const {
    return height;
}
