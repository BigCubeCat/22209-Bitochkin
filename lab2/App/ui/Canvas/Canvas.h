
#ifndef UNTITLED_CANVAS_H
#define UNTITLED_CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Canvas : public QWidget {
public:
    explicit Canvas(QWidget *parent = 0);

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    void setCellSize(int size);

    void setGap(int size);

private:
    char *data;
    size_t width;
    size_t height;

    int cellSize = 10;
    int gapSize = 1;
public slots:

    void redraw(char *data, size_t width, size_t height);
};


#endif //UNTITLED_CANVAS_H
