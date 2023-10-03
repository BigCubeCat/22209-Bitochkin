
#ifndef UNTITLED_CANVAS_H
#define UNTITLED_CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Canvas : public QWidget {
public:
    explicit Canvas(std::vector<std::vector<char>> *data = nullptr,
                    QWidget *parent = 0
    );

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    void setCellSize(int size);

    void setGap(int size);

private:
    std::vector<std::vector<char>> *data;
    int cellSize = 20;
    int gapSize = 1;
public slots:

    void redraw();
};


#endif //UNTITLED_CANVAS_H
