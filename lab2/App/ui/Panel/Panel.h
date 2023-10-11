#ifndef PANEL_H
#define PANEL_H

#include <QWidget>

#include "../Stepper/Stepper.h"
#include "../Rule/Rule.h"
#include "../NeighborhoodSelect/NeighborhoodSelect.h"

#include "../../types/TRules.h"
#include "../../types/TNeighborhood.h"
#include "../../StateStorage/StateStorage.h"
#include "../Conf/Conf.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Panel; }
QT_END_NAMESPACE

class Panel : public QWidget {
Q_OBJECT

public:
    explicit Panel(QWidget *parent = nullptr, StateStorage *s = nullptr);

    ~Panel() override;

private:
    Ui::Panel *ui;
    Stepper *gameStepper;
    Rule *gameRules;
    NeighborhoodSelect *neighborhoodSelect;
    Conf *canvasConfig;

    StateStorage *store;
};


#endif
