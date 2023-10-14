#ifndef UNTITLED_CANVAS_H
#define UNTITLED_CANVAS_H

#include <QPaintEvent>
#include <QPainter>
#include <QWidget>

class Canvas : public QWidget {
    Q_OBJECT
   public:
    explicit Canvas(QWidget *parent = 0);

    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

   private:
    char *data;
    size_t width;
    size_t height;

    int cellSize = 10;
    int gapSize = 1;
    int step = 1;

    QColor borderColor = QColor(100, 100, 100);
    QColor emptyColor = QColor(255, 255, 255);
    QColor aliveColor = QColor(200, 0, 0);

   public slots:

    void setCellSize(int size);

    void setGapSize(int size);

    void redraw(char *data, size_t width, size_t height);

    void setColor(const QColor &color, int index);

   protected:
    void mousePressEvent(QMouseEvent *event) override;

   signals:

    void toggleCell(int row, int col);
};

#endif
