#ifndef RULE_H
#define RULE_H

#include <QWidget>
#include "../../StateStorage/StateStorage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Rule; }
QT_END_NAMESPACE

class Rule : public QWidget {
Q_OBJECT

public:
    explicit Rule(QWidget *parent = nullptr);

    ~Rule() override;

private:
    Ui::Rule *ui;

    std::string bRuleString = "";
    std::string sRuleString = "";

public slots:
    void setB();
    void setS();
    void applySlot();

    void parseTRules(const TRules &);

    void invalidRules();

signals:
    void emitRules(const std::string &);
};

#endif
