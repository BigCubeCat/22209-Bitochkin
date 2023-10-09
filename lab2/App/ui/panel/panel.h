#ifndef PANEL_H
#define PANEL_H

#include <QWidget>

#include "../stepper/stepper.h"
#include "../rule/rule.h"
#include "../neighborhoodselect/neighborhoodselect.h"

#include "../../types/TRules.h"
#include "../../types/TNeighborhood.h"
#include "../../StateStorage/StateStorage.h"
#include "../settings/conf.h"

QT_BEGIN_NAMESPACE
namespace Ui { class panel; }
QT_END_NAMESPACE

class panel : public QWidget {
Q_OBJECT

public:
    explicit panel(QWidget *parent = nullptr, StateStorage *s = nullptr);

    ~panel() override;

private:
    Ui::panel *ui;
    stepper *gameStepper;
    rule *gameRules;
    neighborhoodselect *neighborhoodSelect;
    conf *canvasConfig;

    StateStorage *store;
};


#endif
