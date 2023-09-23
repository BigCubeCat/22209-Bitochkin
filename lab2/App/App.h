#ifndef UNTITLED_APP_H
#define UNTITLED_APP_H

#include <QMainWindow>

#include "../Life/Life.h"
#include "../UI/Canvas/Canvas.h"

class App : public QMainWindow {
Q_OBJECT

public:
    App(QWidget *parent = 0);
    ~App();

private:
    Life *game;
    TNeighborhood *neighborhood;
    TRules *rules;

    Canvas *canvas;

    void setupUi();
};


#endif //UNTITLED_APP_H
