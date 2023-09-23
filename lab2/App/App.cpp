#include "App.h"

#include <QHBoxLayout>
#include <QPushButton>

App::App(QWidget *parent) :
        QMainWindow(parent), game(new Life()),
        rules(new TRules()), neighborhood(new TNeighborhood()) {
    setupUi();
}

App::~App() {
    delete game;
    delete rules;
    delete neighborhood;
}

void App::setupUi() {
    setWindowTitle("Game Of Life");
    auto *mainWidget = new QWidget(this);

    setCentralWidget(mainWidget);

    auto *layout = new QHBoxLayout(mainWidget);

    auto canvas = new Canvas();
    QPushButton *button5 = new QPushButton("Five");

    layout->addWidget(canvas);
    layout->addWidget(button5);
}
