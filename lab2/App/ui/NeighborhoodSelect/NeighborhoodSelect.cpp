#include "NeighborhoodSelect.h"
#include "ui_neighborhoodselect.h"


NeighborhoodSelect::NeighborhoodSelect(QWidget *parent) :
        QWidget(parent), ui(new Ui::NeighborhoodSelect) {
    ui->setupUi(this);
    ui->comboBox->addItem(QString("Moore"));
    ui->comboBox->addItem(QString("von Neumann"));

    QObject::connect(ui->applyButton, &QPushButton::clicked, this, &NeighborhoodSelect::applyClicked);
}

NeighborhoodSelect::~NeighborhoodSelect() {
    delete ui;
}

void NeighborhoodSelect::setN(const TNeighborhood &n) {
    ui->comboBox->setCurrentIndex((n.title == MOORE) ? 0 : 1);
    ui->spinBox->setValue(n.degree);
}

void NeighborhoodSelect::applyClicked() {
    emit applyN((ui->comboBox->currentIndex() == 0) ? MOORE : VON, ui->spinBox->value());
}