#include "StateStorage.h"

#include <QColor>
#include <iostream>

StateStorage::StateStorage() {
    gameTimer = new QTimer(this);
    canvasTimer = new QTimer(this);

    QObject::connect(gameTimer, &QTimer::timeout, this,
                     &StateStorage::tickGame);
    QObject::connect(canvasTimer, &QTimer::timeout, this,
                     &StateStorage::tickCanvas);

    gameTimer->setInterval(100);
    canvasTimer->setInterval(80);

    gameTimer->start();
    canvasTimer->start();

    InitLife(128, 128);
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
    if (life) life->setNeighborhood(n);
    emit updateNeighborhood(n);
}

void StateStorage::toggleLife(int row, int col) {
    if (life) {
        life->toggleCell(row, col);
    }
}

void StateStorage::InitLife(int countRows, int countCols) {
    arenaHeight = countRows;
    arenaWidth = countCols;
    delete life;
    life = new Life(arenaWidth, arenaHeight);
}

char *StateStorage::getArena() {
    if (life) {
        std::cout << "here\n";
        auto answer = life->getArena();
        for (int i = 0; i < 32 * 32; ++i) {
            if (answer[i])
            std::cout << (int)answer[i] << std::endl;
        }
        std::cout << answer << std::endl;
        if (answer) {
            std::cout << "answr\n";
            return answer;
        } else {
        }
    }
    return nullptr;
}

size_t StateStorage::getWidth() const {
    if (life) return life->getWidth();
    return 0;
}

size_t StateStorage::getHeight() const {
    if (life) return life->getHeight();
    return 0;
}

void StateStorage::tickGame() {
    if (isRunning) {
        step();
        isRunning = true;
    }
}

void StateStorage::tickCanvas() {
    if (life) {
        emit redraw(life->getArena(), life->getWidth(), life->getHeight());
    }
}

void StateStorage::step() {
    if (life) {
        life->nextGen();
        isRunning = false;
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

void StateStorage::setCellSize(int size) {
    emit cellSizeSignal(size);
}

void StateStorage::setGapSize(int size) {
    emit gapSizeSignal(size);
}

void StateStorage::setColor(const QColor &color, int index) {
    emit setColorSignal(color, index);
}

QString StateStorage::getRules() {
    if (life) {
        return QString::fromStdString(life->getRules());
    }
    return {""};
}

QString StateStorage::getNeighborhood() {
    if (life) {
        return QString::fromStdString(life->getNeighborhood());
    }
    return {""};
}

bool StateStorage::aliveAt(int index) {
    if (life) {
        if ((*life)[index] != 0) {
            return true;
        }
    }
    return false;
}
