#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <iostream>
#include <QTextStream>
#include "../Canvas/Canvas.h"


mainwindow::mainwindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    store = new StateStorage();
    leftPanel = new panel(this, store);
    ui->mainLayout->addWidget(leftPanel);
    canvas = new Canvas(&store->arena, this);
    ui->scrollArea->setWidget(canvas);

    connect(ui->actionOpen, &QAction::triggered, this, &mainwindow::openFile);
    ui->actionOpen->setShortcut(QKeySequence(tr("Ctrl+o")));

    connect(ui->actionSave, &QAction::triggered, this, &mainwindow::saveFile);
    ui->actionSave->setShortcut(QKeySequence(tr("Ctrl+s")));

    connect(ui->actionSave_As, &QAction::triggered, this, &mainwindow::saveAsFile);
    ui->actionSave_As->setShortcut(QKeySequence(tr("Ctrl+Alt+s")));
}

mainwindow::~mainwindow() {
    delete leftPanel;
    delete canvas;
    delete ui;
    delete store;
}

void mainwindow::openFile() {
    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Life 1.06 file"), "", tr("Life Files (*.life)"));
    std::cout << "filename = " << fileName.toStdString() << "\n";
    readLife();
}

void mainwindow::saveFile() {
    saveLife();
}

void mainwindow::saveAsFile() {
    fileName = QFileDialog::getSaveFileName(
            this, tr("Save File"),
            "",
            tr("Life (*.life)")
    );
    saveFile();
}

void mainwindow::saveLife() {

}

void mainwindow::readLife() {
    store->InitLife();
    QFile inputFile(fileName);
    inputFile.open(QIODevice::ReadOnly);
    if (!inputFile.isOpen())
        return;

    QTextStream stream(&inputFile);
    for (QString line = stream.readLine();
         !line.isNull();
         line = stream.readLine()) {
        QStringList words = line.split(" ");
        if (line.at(0) == QChar('#')) {
            if (words[0] == QString("#T")) {
                this->setWindowTitle(line);
            } else if (words[0] == QString("#R")) {
                store->setRules(words[1].toStdString());
            } else if (words[0] == QString("#N")) {
                ENeighborhood nType = (words[1] == QString("M")) ? MOORE : VON;
                int degree = words[2].toInt();
                store->setNeighborhood(nType, degree);
            } else if (words[0] == QString("#G")) {
                store->resizeLife(words[1].toInt(), words[2].toInt());
            }
        } else {
            store->toggleLife(words[0].toInt(), words[1].toInt());
        }
    };
    canvas->update();
}