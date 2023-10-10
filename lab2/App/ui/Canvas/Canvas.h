#ifndef UNTITLED_CANVAS_H
#define UNTITLED_CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Canvas : public QWidget {
public:
    explicit Canvas(QWidget *parent = 0);

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    char *data;
    size_t width;
    size_t height;

    int cellSize = 10;
    int gapSize = 1;

    QColor borderColor;
    QColor emptyColor;
    QColor aliveColor;

public slots:

    void setCellSize(int size);

    void setGapSize(int size);

    void redraw(char *data, size_t width, size_t height);

    void setColor(QColor color, int index);
};


#endif
