#include "Conf.h"
#include "ui_conf.h"

#include <QColorDialog>
#include <QString>

Conf::Conf(QWidget *parent) :
        QWidget(parent), ui(new Ui::Conf) {
    ui->setupUi(this);

    QObject::connect(ui->cellSizeSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, &Conf::onCellSizeChange);
    QObject::connect(ui->gapSizeSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, &Conf::onGapSizeChange);

    QObject::connect(ui->aliveButton, &QPushButton::clicked, this, &Conf::aliveColor);
    QObject::connect(ui->diedButton, &QPushButton::clicked, this, &Conf::emptyColor);
    QObject::connect(ui->borderButton, &QPushButton::clicked, this, &Conf::borderColor);

    ui->aliveButton->setStyleSheet(QString("background-color: %1").arg(currentAliveColor.name()));
    ui->diedButton->setStyleSheet(QString("background-color: %1").arg(currentEmptyColor.name()));
    ui->borderButton->setStyleSheet(QString("background-color: %1").arg(currentBorderColor.name()));
}

Conf::~Conf() {
    delete ui;
}

void Conf::onCellSizeChange(int value) {
    emit setCellSize(value);
}

void Conf::onGapSizeChange(int value) {
    emit setGapSize(value);
}

void Conf::aliveColor() {
    currentAliveColor = QColorDialog::getColor();
    if (currentAliveColor.isValid()) {
        QString qss = QString("background-color: %1").arg(currentAliveColor.name());
        ui->aliveButton->setStyleSheet(qss);
        emit changeColor(currentAliveColor, 0);
    }
}


void Conf::emptyColor() {
    currentEmptyColor = QColorDialog::getColor();
    if (currentEmptyColor.isValid()) {
        QString qss = QString("background-color: %1").arg(currentEmptyColor.name());
        ui->diedButton->setStyleSheet(qss);
        emit changeColor(currentEmptyColor, 1);
    }
}

void Conf::borderColor() {
    currentBorderColor = QColorDialog::getColor();
    if (currentBorderColor.isValid()) {
        QString qss = QString("background-color: %1").arg(currentBorderColor.name());
        ui->borderButton->setStyleSheet(qss);
        emit changeColor(currentBorderColor, 2);
    }
}
