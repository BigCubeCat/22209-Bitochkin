//
// Created by bigcubecat on 28.09.23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_rule.h" resolved

#include "rule.h"
#include "ui_rule.h"


rule::rule(QWidget *parent) :
        QWidget(parent), ui(new Ui::rule) {
    ui->setupUi(this);
}

rule::~rule() {
    delete ui;
}
