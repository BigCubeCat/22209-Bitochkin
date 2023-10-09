#include "panel.h"
#include "ui_panel.h"


panel::panel(QWidget *parent, StateStorage *store) :
        QWidget(parent), ui(new Ui::panel), store(store) {
    ui->setupUi(this);

    gameStepper = new stepper(this);
    gameRules = new rule(this);
    neighborhoodSelect = new neighborhoodselect(this);
    canvasConfig = new conf(this);

    ui->panelLayout->addWidget(gameStepper);
    ui->panelLayout->addWidget(gameRules);
    ui->panelLayout->addWidget(neighborhoodSelect);
    ui->panelLayout->addWidget(canvasConfig);

    this->setMaximumWidth(301);

    QObject::connect(store, &StateStorage::updateNeighborhood, neighborhoodSelect, &neighborhoodselect::setN);
    QObject::connect(neighborhoodSelect, &neighborhoodselect::applyN, store, &StateStorage::setNeighborhood);

    QObject::connect(store, &StateStorage::invalidRule, gameRules, &rule::invalidRules);
    QObject::connect(store, &StateStorage::updateRules, gameRules, &rule::parseTRules);
    QObject::connect(gameRules, &rule::emitRules, store, &StateStorage::setRules);

    QObject::connect(gameStepper, &stepper::step, store, &StateStorage::step);
    QObject::connect(gameStepper, &stepper::stop, store, &StateStorage::stop);
    QObject::connect(gameStepper, &stepper::run, store, &StateStorage::run);
    QObject::connect(gameStepper, &stepper::setSpeed, store, &StateStorage::setSpeed);

    QObject::connect(canvasConfig, &conf::setCellSize, store, &StateStorage::setCellSize);
    QObject::connect(canvasConfig, &conf::setGapSize, store, &StateStorage::setGapSize);
}

panel::~panel() {
    delete neighborhoodSelect;
    delete gameStepper;
    delete gameRules;
    delete canvasConfig;
    delete ui;
}
