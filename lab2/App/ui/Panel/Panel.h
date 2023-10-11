#ifndef PANEL_H
#define PANEL_H

#include <QWidget>

#include "../stepper/stepper.h"
#include "../rule/rule.h"
#include "../NeighborhoodSelect/NeighborhoodSelect.h"

#include "../../types/TRules.h"
#include "../../types/TNeighborhood.h"
#include "../../StateStorage/StateStorage.h"
#include "../settings/conf.h"

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
    stepper *gameStepper;
    rule *gameRules;
    NeighborhoodSelect *neighborhoodSelect;
    conf *canvasConfig;

    StateStorage *store;
};


#endif
