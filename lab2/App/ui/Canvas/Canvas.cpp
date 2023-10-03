#include "Canvas.h"

#include <iostream>

Canvas::Canvas(
        std::vector<std::vector<char>> *data,
        QWidget *parent) : QWidget(parent), data(data) {
}

void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter;
    painter.begin(this);
    painter.fillRect(event->rect(), Qt::green);
    painter.setBrush(QBrush(QColor(20, 128, 129)));
    int step = cellSize + gapSize;
    std::cout << data->size();
    for (size_t i = 0; i < data->size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            painter.drawRect(i * step, j * step, cellSize, cellSize);
        }
    }
    QWidget::paintEvent(event);
    painter.end();
}

void Canvas::redraw() {

}

void Canvas::setCellSize(int size) {
    cellSize = size;
}

void Canvas::setGap(int size) {
    gapSize = size;
}
