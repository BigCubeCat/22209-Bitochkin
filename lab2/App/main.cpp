#include <QApplication>
#include <QPushButton>

#include "./ui/mainwindow/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto app = mainwindow();
    app.show();
    return QApplication::exec();
}
