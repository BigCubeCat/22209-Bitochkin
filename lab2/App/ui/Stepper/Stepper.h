#ifndef STEPPER_H
#define STEPPER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Stepper;
}
QT_END_NAMESPACE

class Stepper : public QWidget {
    Q_OBJECT

   public:
    explicit Stepper(QWidget *parent = nullptr);

    ~Stepper() override;

   private:
    Ui::Stepper *ui;
   private slots:

    void stepSlot();

    void stopSlot();

    void runSlot();

    void setSpeedSlot(int value);

   signals:

    void step();

    void stop();

    void run();

    void setSpeed(int value);
};

#endif
