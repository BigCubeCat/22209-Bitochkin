#include <QApplication>
#include <QPushButton>

#include "UI/Canvas/Canvas.h"
#include "App/App.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto app = App();
    app.show();
    return QApplication::exec();
}
