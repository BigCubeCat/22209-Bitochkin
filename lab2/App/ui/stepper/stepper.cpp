#include "stepper.h"
#include "ui_stepper.h"


stepper::stepper(QWidget *parent) :
        QWidget(parent), ui(new Ui::stepper) {
    ui->setupUi(this);
    QObject::connect(ui->runButton, &QPushButton::clicked, this, &stepper::runSlot);
    QObject::connect(ui->stepButton, &QPushButton::clicked, this, &stepper::stepSlot);
    QObject::connect(ui->stopButton, &QPushButton::clicked, this, &stepper::stopSlot);

    QObject::connect(ui->speedSlider, &QSlider::valueChanged, this, &stepper::setSpeedSlot);
}

stepper::~stepper() {
    delete ui;
}

void stepper::stepSlot() {
    emit step();
}

void stepper::stopSlot() {
    emit stop();
}

void stepper::runSlot() {
    emit run();
}

void stepper::setSpeedSlot(int value) {
    emit setSpeed(value);
}
