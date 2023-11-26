#include "Canvas.h"

#include <QTimer>

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    data = nullptr;
}

void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter;
    painter.begin(this);
    painter.fillRect(event->rect(), borderColor);

    QBrush brush;
    if (data) {
        for (size_t i = 0; i < height; ++i) {
            for (size_t j = 0; j < width; ++j) {
                if ((*data)[i * width + j] == ALIVE) {
                    brush = QBrush(aliveColor);
                } else {
                    brush = QBrush(emptyColor);
                }
                painter.fillRect(i * step + gapSize, j * step + gapSize,
                                 cellSize, cellSize, brush);
            }
        }
    }
    QWidget::paintEvent(event);
    painter.end();
}

void Canvas::redraw(Arena *d, size_t w, size_t h) {
    data = d;
    width = w;
    height = h;
    step = cellSize + gapSize;
    setFixedWidth(width * step + gapSize);
    setFixedHeight(height * step + gapSize);
    update();
}

void Canvas::setCellSize(int size) {
    cellSize = size;
    setFixedWidth(width * step + gapSize);
    setFixedHeight(height * step + gapSize);
    update();
}

void Canvas::setGapSize(int size) {
    gapSize = size;
    setFixedWidth(width * step + gapSize);
    setFixedHeight(height * step + gapSize);
    update();
}

void Canvas::setColor(const QColor &color, int index) {
    if (index == 0) {
        aliveColor = color;
    } else if (index == 1) {
        emptyColor = color;
    } else {
        borderColor = color;
    }
    update();
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    int x = event->x() / step;
    int y = event->y() / step;
    emit toggleCell(x, y);
    update();
}
