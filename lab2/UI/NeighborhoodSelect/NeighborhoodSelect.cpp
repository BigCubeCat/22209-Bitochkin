#include "NeighborhoodSelect.h"

#include <QPainter>

namespace {
    const int CELL_SIZE = 25;
    const int GAP_SIZE = 5;
};

NeighborhoodSelect::NeighborhoodSelect(QWidget *parent, TNeighborhood *n) : QWidget(parent) {
    setNeighborhood(n);
}

void NeighborhoodSelect::setNeighborhood(TNeighborhood *n) {
    neighborhood = n;
    size = 2 * neighborhood->degree + 1;
    data.resize(size * size);
    int center = (neighborhood->degree + 1) * size;

    for (int i = 0; i < size; ++i) {
        if (i == center) {
            data[i] = 2;
            continue;
        }
        data[i] = 0;
    }
    for (const auto &p: n->points) {
        data[center + p.first * size + neighborhood->degree + p.second] = 1;
    }
    setupUi();
}

void NeighborhoodSelect::setupUi() {
    int renderSize = (CELL_SIZE + GAP_SIZE) * (2 * neighborhood->degree + 1) + GAP_SIZE;
    setFixedSize(renderSize, renderSize);

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            int value = data[row * neighborhood->degree + neighborhood->degree + col];
            if (value == 2) {
                QPainter painter(this); // Создаём объект отрисовщика
                // Устанавливаем кисть абриса
                painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
                painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
                painter.drawEllipse(100, 50, 150, 150);
            }
        }
    }
}

void NeighborhoodSelect::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter.drawEllipse(100, 50, 150, 150);
}
