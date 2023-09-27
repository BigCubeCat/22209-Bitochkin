#ifndef UNTITLED_NEIGHBORHOODSELECT_H
#define UNTITLED_NEIGHBORHOODSELECT_H

#include <vector>

#include <QWidget>

#include "../../types/TNeighborhood.h"

class NeighborhoodSelect: public QWidget{
public:
    explicit NeighborhoodSelect(QWidget *parent = 0, TNeighborhood *n = 0);
    void setNeighborhood(TNeighborhood *n);
private:
    void setupUi();

    TNeighborhood *neighborhood{};
};


#endif //UNTITLED_NEIGHBORHOODSELECT_H
