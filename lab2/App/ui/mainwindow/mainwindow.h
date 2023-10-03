#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../panel/panel.h"
#include "../../Life/Life.h"
#include "../../types/TRules.h"
#include "../../StateStorage/StateStorage.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

    Life *life;

private:
    Ui::mainwindow *ui;
    StateStorage *store;
    panel *leftPanel;

    QString fileName;

    void saveLife();
    void readLife();
public slots:

    void openFile();

    void saveFile();

    void saveAsFile();
};


#endif
