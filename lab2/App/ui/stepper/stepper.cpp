//
// Created by bigcubecat on 28.09.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_stepper.h" resolved

#include "stepper.h"
#include "ui_stepper.h"


stepper::stepper(QWidget *parent) :
        QWidget(parent), ui(new Ui::stepper) {
    ui->setupUi(this);
}

stepper::~stepper() {
    delete ui;
}
