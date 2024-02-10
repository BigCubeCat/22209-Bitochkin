#include "Panel.h"

#include "ui_panel.h"

Panel::Panel(QWidget *parent, StateStorage *store)
    : QWidget(parent), ui(new Ui::Panel), store(store) {
    ui->setupUi(this);

    gameStepper = new Stepper(this);
    gameRules = new Rule(this);
    neighborhoodSelect = new NeighborhoodSelect(this);
    canvasConfig = new Conf(this);

    ui->panelLayout->addWidget(gameStepper);
    ui->panelLayout->addWidget(gameRules);
    ui->panelLayout->addWidget(neighborhoodSelect);
    ui->panelLayout->addWidget(canvasConfig);

    this->setMaximumWidth(301);

    QObject::connect(store, &StateStorage::updateNeighborhood,
                     neighborhoodSelect, &NeighborhoodSelect::setN);
    QObject::connect(neighborhoodSelect, &NeighborhoodSelect::applyN, store,
                     &StateStorage::setNeighborhood);

    QObject::connect(store, &StateStorage::invalidRule, gameRules,
                     &Rule::invalidRules);
    QObject::connect(store, &StateStorage::updateRules, gameRules,
                     &Rule::parseTRules);
    QObject::connect(gameRules, &Rule::emitRules, store,
                     &StateStorage::setRules);

    QObject::connect(gameStepper, &Stepper::step, store, &StateStorage::step);
    QObject::connect(gameStepper, &Stepper::stop, store, &StateStorage::stop);
    QObject::connect(gameStepper, &Stepper::run, store, &StateStorage::run);
    QObject::connect(gameStepper, &Stepper::setSpeed, store,
                     &StateStorage::setSpeed);

    QObject::connect(canvasConfig, &Conf::setCellSize, store,
                     &StateStorage::setCellSize);
    QObject::connect(canvasConfig, &Conf::setGapSize, store,
                     &StateStorage::setGapSize);

    QObject::connect(canvasConfig, &Conf::changeColor, store,
                     &StateStorage::setColor);
}

Panel::~Panel() {
    delete neighborhoodSelect;
    delete gameStepper;
    delete gameRules;
    delete canvasConfig;
    delete ui;
}
