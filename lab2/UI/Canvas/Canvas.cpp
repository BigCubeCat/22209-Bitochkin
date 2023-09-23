#include "Canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.fillRect(event->rect(), Qt::red);
    QWidget::paintEvent(event);
    painter.end();
}

void Canvas::redraw() {

}
