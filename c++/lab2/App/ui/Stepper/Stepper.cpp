#include "Stepper.h"

#include "ui_stepper.h"

Stepper::Stepper(QWidget *parent) : QWidget(parent), ui(new Ui::Stepper) {
    ui->setupUi(this);
    QObject::connect(ui->runButton, &QPushButton::clicked, this,
                     &Stepper::runSlot);
    QObject::connect(ui->stepButton, &QPushButton::clicked, this,
                     &Stepper::stepSlot);
    QObject::connect(ui->stopButton, &QPushButton::clicked, this,
                     &Stepper::stopSlot);

    QObject::connect(ui->speedSlider, &QSlider::valueChanged, this,
                     &Stepper::setSpeedSlot);
}

Stepper::~Stepper() {
    delete ui;
}

void Stepper::stepSlot() {
    emit step();
}

void Stepper::stopSlot() {
    emit stop();
}

void Stepper::runSlot() {
    emit run();
}

void Stepper::setSpeedSlot(int value) {
    emit setSpeed(value);
}
