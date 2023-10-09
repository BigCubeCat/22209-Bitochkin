#include "Canvas.h"

#include <QTimer>

#include <iostream>

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    data = nullptr;
}

void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter;
    painter.begin(this);
    painter.fillRect(event->rect(), Qt::darkBlue);
    int step = cellSize + gapSize;
    std::cout << cellSize << " " << gapSize << "\n";

    QBrush brush;
    if (data) {
        for (size_t i = 0; i < height; ++i) {
            for (size_t j = 0; j < width; ++j) {
                if (data[i * width + j] != 0) {
                    brush = QBrush(QColor(200, 20, 20));
                } else {
                    brush = QBrush(QColor(255, 255, 255));
                }
                painter.fillRect(i * step, j * step, cellSize, cellSize, brush);
            }
        }
    }
    QWidget::paintEvent(event);
    painter.end();
}

void Canvas::redraw(char *d, size_t w, size_t h) {
    data = d;
    width = w;
    height = h;
    setFixedWidth(width * (cellSize + gapSize));
    setFixedHeight(height * (cellSize + gapSize));
    update();
}

void Canvas::setCellSize(int size) {
    cellSize = size;
    setFixedWidth(width * (cellSize + gapSize));
    setFixedHeight(height * (cellSize + gapSize));
    update();
}

void Canvas::setGapSize(int size) {
    gapSize = size;
    setFixedWidth(width * (cellSize + gapSize));
    setFixedHeight(height * (cellSize + gapSize));
    update();
}
