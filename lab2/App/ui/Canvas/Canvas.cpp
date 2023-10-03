#include "Canvas.h"

#include <iostream>
#include <QTimer>

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    data = nullptr;
}

void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter;
    painter.begin(this);
    painter.fillRect(event->rect(), Qt::green);
    int step = cellSize + gapSize;

    if (data) {
        for (size_t i = 0; i < height; ++i) {
            for (size_t j = 0; j < width; ++j) {
                if (data[i * width + j] != 0) {
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
}

void Canvas::setGap(int size) {
    gapSize = size;
}
