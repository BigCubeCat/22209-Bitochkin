#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    leftPanel = new panel(this);
    ui->mainLayout->addWidget(leftPanel);
}

mainwindow::~mainwindow() {
    delete leftPanel;
    delete ui;
}
