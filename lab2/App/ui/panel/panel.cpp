#include "panel.h"
#include "ui_panel.h"


panel::panel(QWidget *parent) :
        QWidget(parent), ui(new Ui::panel) {
    ui->setupUi(this);

    gameStepper = new stepper(this);
    gameRules = new rule(this);
    neighborhoodSelect = new neighborhoodselect(this);

    ui->panelLayout->addWidget(gameStepper);
    ui->panelLayout->addWidget(gameRules);
    ui->panelLayout->addWidget(neighborhoodSelect);

    this->setMaximumWidth(301);
}

panel::~panel() {
    delete neighborhoodSelect;
    delete gameStepper;
    delete gameRules;
    delete ui;
}
