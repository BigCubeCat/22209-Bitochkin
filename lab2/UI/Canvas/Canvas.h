
#ifndef UNTITLED_CANVAS_H
#define UNTITLED_CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Canvas : public QWidget{
public:
    std::vector<std::vector<char>> data;
    explicit Canvas(QWidget *parent=0);

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    int cellSize = 20;
    int gapSize = 1;
public slots:
    void redraw();
};


#endif //UNTITLED_CANVAS_H
