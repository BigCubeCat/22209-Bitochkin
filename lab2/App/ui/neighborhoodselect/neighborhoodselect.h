#ifndef NEIGHBORHOODSELECT_H
#define NEIGHBORHOODSELECT_H

#include <QWidget>
#include "../../types/TNeighborhood.h"


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

public slots:

    void setN(const TNeighborhood &n);

    void applyClicked();

signals:

    void applyN(const ENeighborhood title, int deg);
};


#endif
