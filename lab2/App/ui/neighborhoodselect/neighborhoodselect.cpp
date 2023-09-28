//
// Created by bigcubecat on 28.09.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_neighborhoodselect.h" resolved

#include "neighborhoodselect.h"
#include "ui_neighborhoodselect.h"


neighborhoodselect::neighborhoodselect(QWidget *parent) :
        QWidget(parent), ui(new Ui::neighborhoodselect) {
    ui->setupUi(this);
}

neighborhoodselect::~neighborhoodselect() {
    delete ui;
}
