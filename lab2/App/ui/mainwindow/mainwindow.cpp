#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    store = new StateStorage();
    leftPanel = new panel(this, store);
    ui->mainLayout->addWidget(leftPanel);
}

mainwindow::~mainwindow() {
    delete leftPanel;
    delete ui;
    delete store;
}
