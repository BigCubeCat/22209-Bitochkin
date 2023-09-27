#include "App.h"

#include <QHBoxLayout>
#include <QPushButton>

#include "../UI/NeighborhoodSelect/NeighborhoodSelect.h"

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
    auto *panel = new QWidget(mainWidget);
    setCentralWidget(mainWidget);

    auto *mainLayout = new QHBoxLayout(mainWidget);
    auto *panelLayout = new QVBoxLayout(panel);

    auto nSelect = new NeighborhoodSelect(nullptr, neighborhood);
    auto canvas = new Canvas();
    QPushButton *button5 = new QPushButton("Five");

    panelLayout->addWidget(nSelect);

    mainLayout->addWidget(panel);
    mainLayout->addWidget(canvas);
    mainLayout->addWidget(button5);
}
