#include "conf.h"
#include "ui_conf.h"

conf::conf(QWidget *parent) :
        QWidget(parent), ui(new Ui::conf) {
    ui->setupUi(this);

    QObject::connect(ui->cellSizeSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, &conf::onCellSizeChange);
    QObject::connect(ui->gapSizeSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, &conf::onGapSizeChange);
}

conf::~conf() {
    delete ui;
}

void conf::onCellSizeChange(int value) {
    emit setCellSize(value);
}

void conf::onGapSizeChange(int value) {
    emit setGapSize(value);
}
