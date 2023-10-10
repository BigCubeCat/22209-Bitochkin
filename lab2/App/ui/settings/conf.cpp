#include "conf.h"
#include "ui_conf.h"

#include <QColorDialog>
#include <QString>

conf::conf(QWidget *parent) :
        QWidget(parent), ui(new Ui::conf) {
    ui->setupUi(this);

    QObject::connect(ui->cellSizeSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, &conf::onCellSizeChange);
    QObject::connect(ui->gapSizeSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, &conf::onGapSizeChange);

    QObject::connect(ui->aliveButton, &QPushButton::clicked, this, &conf::aliveColor);
    QObject::connect(ui->diedButton, &QPushButton::clicked, this, &conf::emptyColor);
    QObject::connect(ui->borderButton, &QPushButton::clicked, this, &conf::borderColor);
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

void conf::aliveColor() {
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QString qss = QString("background-color: %1").arg(color.name());
        ui->aliveButton->setStyleSheet(qss);
        emit changeColor(color, 0);
    }
}


void conf::emptyColor() {
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QString qss = QString("background-color: %1").arg(color.name());
        ui->diedButton->setStyleSheet(qss);
        emit changeColor(color, 1);
    }
}

void conf::borderColor() {
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QString qss = QString("background-color: %1").arg(color.name());
        ui->borderButton->setStyleSheet(qss);
        emit changeColor(color, 2);
    }
}
