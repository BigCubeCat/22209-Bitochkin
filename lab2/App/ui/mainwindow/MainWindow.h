#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../../FileWorker/FileWorker.h"
#include "../../Life/Life.h"
#include "../../StateStorage/StateStorage.h"
#include "../../types/TRules.h"
#include "../Canvas/Canvas.h"
#include "../Panel/Panel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    void setCellSize(int size);

    void setGapSize(int size);

   private:
    Ui::MainWindow *ui;
    StateStorage *store;
    Panel *leftPanel;
    Canvas *canvas;
    FileWorker *fw;

    void saveLife();

    void readLife();

   public slots:

    void openFile();

    void saveFile();

    void saveAsFile();

    void setTitle(const QString &title);
};

#endif
