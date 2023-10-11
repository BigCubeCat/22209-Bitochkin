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
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QString qss = QString("background-color: %1").arg(color.name());
        ui->aliveButton->setStyleSheet(qss);
        emit changeColor(color, 0);
    }
}


void Conf::emptyColor() {
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QString qss = QString("background-color: %1").arg(color.name());
        ui->diedButton->setStyleSheet(qss);
        emit changeColor(color, 1);
    }
}

void Conf::borderColor() {
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QString qss = QString("background-color: %1").arg(color.name());
        ui->borderButton->setStyleSheet(qss);
        emit changeColor(color, 2);
    }
}
