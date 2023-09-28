#ifndef STEPPER_H
#define STEPPER_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class stepper; }
QT_END_NAMESPACE

class stepper : public QWidget {
Q_OBJECT

public:
    explicit stepper(QWidget *parent = nullptr);

    ~stepper() override;

private:
    Ui::stepper *ui;
};


#endif
