#include "StateStorage.h"

#include <QColor>
#include <iostream>

StateStorage::StateStorage(QObject *parent) : QObject(parent) {
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
    life = std::make_shared<Life>(arenaWidth, arenaHeight);
}
Arena &StateStorage::getArena() const {
    return life->getArena();
}

size_t StateStorage::getWidth() const {
    if (life) return life->getArena().getWidth();
    return 0;
}

size_t StateStorage::getHeight() const {
    if (life) return life->getArena().getHeight();
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
        emit redraw(life->getArena());
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
        auto arena = life->getArena();
        return arena[index] == ALIVE;
    }
    return false;
}
