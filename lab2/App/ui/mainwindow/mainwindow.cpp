#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <iostream>
#include <QTextStream>
#include <QString>


mainwindow::mainwindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    store = new StateStorage();
    leftPanel = new Panel(this, store);
    ui->mainLayout->addWidget(leftPanel);
    canvas = new Canvas(this);
    ui->scrollArea->setWidget(canvas);
    fw = new FileWorker(store);

    connect(ui->actionOpen, &QAction::triggered, this, &mainwindow::openFile);
    ui->actionOpen->setShortcut(QKeySequence(tr("Ctrl+o")));

    connect(ui->actionSave, &QAction::triggered, this, &mainwindow::saveFile);
    ui->actionSave->setShortcut(QKeySequence(tr("Ctrl+s")));

    connect(ui->actionSave_As, &QAction::triggered, this, &mainwindow::saveAsFile);
    ui->actionSave_As->setShortcut(QKeySequence(tr("Ctrl+Alt+s")));

    QObject::connect(store, &StateStorage::redraw, canvas, &Canvas::redraw);
    QObject::connect(store, &StateStorage::gapSizeSignal, canvas, &Canvas::setGapSize);
    QObject::connect(store, &StateStorage::cellSizeSignal, canvas, &Canvas::setCellSize);

    QObject::connect(store, &StateStorage::setColorSignal, canvas, &Canvas::setColor);

    QObject::connect(canvas, &Canvas::toggleCell, store, &StateStorage::toggleLife);

    QObject::connect(fw, &FileWorker::setWindowTitle, this, &mainwindow::setTitle);
}

mainwindow::~mainwindow() {
    delete leftPanel;
    delete canvas;
    delete ui;
    delete store;
}

void mainwindow::openFile() {
    auto fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Life 1.06 file"), "", tr("Life Files (*.life)"));
    fw->setFileName(fileName);
    readLife();
}

void mainwindow::saveFile() {
    saveLife();
}

void mainwindow::saveAsFile() {
    auto fileName = QFileDialog::getSaveFileName(
            this, tr("Save File"),
            "",
            tr("Life (*.life)")
    );
    fw->setFileName(fileName);
    saveFile();
}

void mainwindow::saveLife() {
    fw->saveFile();
}

void mainwindow::readLife() {
    auto [text, status] = fw->readFile();
    std::cout << text.toStdString() << " " << status << "\n";
    canvas->redraw(store->getArena(), store->getWidth(), store->getHeight());
}

void mainwindow::setCellSize(int size) {
    if (canvas)
        canvas->setCellSize(size);
}

void mainwindow::setGapSize(int size) {
    if (canvas)
        canvas->setCellSize(size);
}

void mainwindow::setTitle(const QString &title) {
    this->setWindowTitle(title);
}
