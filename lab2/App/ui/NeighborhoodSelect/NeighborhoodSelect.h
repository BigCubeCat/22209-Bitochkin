#ifndef NEIGHBORHOODSELECT_H
#define NEIGHBORHOODSELECT_H

#include <QWidget>
#include "../../types/TNeighborhood.h"


QT_BEGIN_NAMESPACE
namespace Ui { class NeighborhoodSelect; }
QT_END_NAMESPACE

class NeighborhoodSelect : public QWidget {
Q_OBJECT

public:
    explicit NeighborhoodSelect(QWidget *parent = nullptr);

    ~NeighborhoodSelect() override;

private:
    Ui::NeighborhoodSelect *ui;

public slots:

    void setN(const TNeighborhood &n);

    void applyClicked();

signals:

    void applyN(const ENeighborhood title, int deg);
};


#endif
