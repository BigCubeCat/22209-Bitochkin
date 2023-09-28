#ifndef NEIGHBORHOODSELECT_H
#define NEIGHBORHOODSELECT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class neighborhoodselect; }
QT_END_NAMESPACE

class neighborhoodselect : public QWidget {
Q_OBJECT

public:
    explicit neighborhoodselect(QWidget *parent = nullptr);

    ~neighborhoodselect() override;

private:
    Ui::neighborhoodselect *ui;
};


#endif
