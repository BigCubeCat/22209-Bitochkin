#include "MainWindow.h"

#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include <iostream>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    store = new StateStorage();
    leftPanel = new Panel(this, store);
    ui->mainLayout->addWidget(leftPanel);
    canvas = new Canvas(this);
    ui->scrollArea->setWidget(canvas);
    fw = new FileWorker(store);

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    ui->actionOpen->setShortcut(QKeySequence(tr("Ctrl+o")));

    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    ui->actionSave->setShortcut(QKeySequence(tr("Ctrl+s")));

    connect(ui->actionSave_As, &QAction::triggered, this,
            &MainWindow::saveAsFile);
    ui->actionSave_As->setShortcut(QKeySequence(tr("Ctrl+Alt+s")));

    QObject::connect(store, &StateStorage::redraw, canvas, &Canvas::redraw);
    QObject::connect(store, &StateStorage::gapSizeSignal, canvas,
                     &Canvas::setGapSize);
    QObject::connect(store, &StateStorage::cellSizeSignal, canvas,
                     &Canvas::setCellSize);

    QObject::connect(store, &StateStorage::setColorSignal, canvas,
                     &Canvas::setColor);

    QObject::connect(canvas, &Canvas::toggleCell, store,
                     &StateStorage::toggleLife);

}

MainWindow::~MainWindow() {
    delete leftPanel;
    delete canvas;
    delete ui;
    delete store;
}

void MainWindow::openFile() {
    auto fileName = QFileDialog::getOpenFileName(
        this, tr("Open Life 1.06 file"), "", tr("Life Files (*.life)"));
    fw->setFileName(fileName);
    readLife();
    this->setWindowTitle(fw->getTitle());
}

void MainWindow::saveFile() {
    saveLife();
}

void MainWindow::saveAsFile() {
    auto fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
                                                 tr("Life (*.life)"));
    fw->setFileName(fileName);
    saveFile();
}

void MainWindow::saveLife() {
    fw->saveFile();
}

void MainWindow::readLife() {
    auto [text, status] = fw->readFile();
    std::cout << text.toStdString() << " " << status << "\n";
    canvas->redraw(store->getArena(), store->getWidth(), store->getHeight());
}

void MainWindow::setCellSize(int size) {
    if (canvas) canvas->setCellSize(size);
}

void MainWindow::setGapSize(int size) {
    if (canvas) canvas->setCellSize(size);
}
