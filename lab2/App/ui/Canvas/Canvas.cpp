#include "Canvas.h"

#include <iostream>
#include <QTimer>

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    data = nullptr;
}

void Canvas::paintEvent(QPaintEvent *event) {
    std::cout << "paintEvent\n";
    QPainter painter;
    painter.begin(this);
    painter.fillRect(event->rect(), Qt::green);
    int step = cellSize + gapSize;

    if (data) {
        std::cout << "here\n";
        for (size_t i = 0; i < 128; ++i) {
            for (size_t j = 0; j < 128; ++j) {
                if (data->at(i).at(j)) {
                    painter.setBrush(QBrush(QColor(20, 128, 129)));
                } else {
                    painter.setBrush(QBrush(QColor(127, 128, 129)));
                }
                painter.drawRect(i * step, j * step, cellSize, cellSize);
            }
        }
    }
    QWidget::paintEvent(event);
    painter.end();
}

void Canvas::redraw(std::vector<std::vector<char>> *d) {
    data = d;
    std::cout << "redraw\n";
    update();
}

void Canvas::setCellSize(int size) {
    cellSize = size;
}

void Canvas::setGap(int size) {
    gapSize = size;
}
