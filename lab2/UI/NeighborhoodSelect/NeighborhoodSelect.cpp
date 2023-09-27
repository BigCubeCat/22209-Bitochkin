#include "NeighborhoodSelect.h"

#include <QPushButton>
#include <QGridLayout>

namespace {
    const int CELL_SIZE = 25;
    const int GAP_SIZE = 5;
};

NeighborhoodSelect::NeighborhoodSelect(QWidget *parent, TNeighborhood *n) : QWidget(parent) {
    setNeighborhood(n);
}

void NeighborhoodSelect::setNeighborhood(TNeighborhood *n) {
    neighborhood = n;
    setupUi();
}

void NeighborhoodSelect::setupUi() {
    auto *mainWidget = new QWidget(this);
    auto *gridLayout = new QVBoxLayout(mainWidget);
    mainWidget->setLayout(gridLayout);

    int size = neighborhood->degree * 2 + 1;
    for (int i = 0; i < size; ++i) {
        auto *wgt = new QWidget();
        auto *row = new QHBoxLayout();
        for (int j = 0; j < size; ++j) {
            auto *button = new QPushButton("", this);
            button->setFixedSize(QSize(30, 30));
            row->addWidget(button);
        }
        row->addWidget(wgt);
        gridLayout->addWidget(wgt);
    }
}
