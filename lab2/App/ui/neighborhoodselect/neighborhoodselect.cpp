#include "neighborhoodselect.h"
#include "ui_neighborhoodselect.h"


neighborhoodselect::neighborhoodselect(QWidget *parent) :
        QWidget(parent), ui(new Ui::neighborhoodselect) {
    ui->setupUi(this);
    ui->comboBox->addItem(QString("Moore"));
    ui->comboBox->addItem(QString("von Neumann"));

    QObject::connect(ui->applyButton, &QPushButton::clicked, this, &neighborhoodselect::applyClicked);
}

neighborhoodselect::~neighborhoodselect() {
    delete ui;
}

void neighborhoodselect::setN(const TNeighborhood &n) {
    ui->comboBox->setCurrentIndex((n.title == MOORE) ? 0 : 1);
    ui->spinBox->setValue(n.degree);
}

void neighborhoodselect::applyClicked() {
    emit applyN((ui->comboBox->currentIndex() == 0) ? MOORE : VON, ui->spinBox->value());
}