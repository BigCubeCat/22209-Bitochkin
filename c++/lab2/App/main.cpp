#include <QApplication>
#include <QPushButton>

#include "./ui/mainwindow/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto app = MainWindow();
    app.show();
    return QApplication::exec();
}
