#include "StateStorage.h"

#include <iostream>

StateStorage::StateStorage() {
    gameTimer = new QTimer(this);
    canvasTimer = new QTimer(this);

    QObject::connect(gameTimer, &QTimer::timeout, this, &StateStorage::tickGame);
    QObject::connect(canvasTimer, &QTimer::timeout, this, &StateStorage::tickCanvas);

    gameTimer->setInterval(300);
    canvasTimer->setInterval(100);

    gameTimer->start();
    canvasTimer->start();
}

StateStorage::~StateStorage() {
    delete canvasTimer;
    canvasTimer = nullptr;
    delete gameTimer;
    gameTimer = nullptr;
}

void StateStorage::setRules(const std::string &newRules) {
    try {
        auto r = TRules(newRules);
        life->setRules(r);
        emit updateRules(r);
    } catch (const std::invalid_argument &ex) {
        emit invalidRule();
    }
}

void StateStorage::setNeighborhood(ENeighborhood newNeigh, int degree) {
    auto n = TNeighborhood(newNeigh, degree);
    if (life)
        life->setNeighborhood(n);
    emit updateNeighborhood(n);
}

void StateStorage::toggleLife(int row, int col) {
    std::cout << "toggle " << row << " " << col << "\n";
    if (life)
        life->toggleCell(row, col);
}

void StateStorage::InitLife(int countRows, int countCols) {
    arenaHeight = countRows;
    arenaWidth = countCols;
    life = new Life(arenaWidth, arenaHeight);
}

char *StateStorage::getArena() {
    if (life) {
        auto answer = life->getArena();
        if (answer) {
            return answer;
        } else {
            std::cout << "shit\n";
        }
    }
    return nullptr;
}

size_t StateStorage::getWidth() const {
    if (life)
        return life->getWidth();
    return 0;
}

size_t StateStorage::getHeight() const {
    if (life)
        return life->getHeight();
    return 0;
}

void StateStorage::tickGame() {
    if (isRunning) {
        std::cout << "tick game\n";
        step();
        needRedraw = true;
    }
}

void StateStorage::tickCanvas() {
    if (needRedraw && life) {
        emit redraw(life->getArena(), life->getWidth(), life->getHeight());
        needRedraw = false;
    }
}

void StateStorage::step() {
    if (life) {
        std::cout << "next gen\n";
        life->nextGen();
        needRedraw = true;
    }
}

void StateStorage::stop() {
    isRunning = false;
}

void StateStorage::run() {
    isRunning = true;
}

void StateStorage::setSpeed(int value) {
    gameTimer->setInterval(200 - value);
}
