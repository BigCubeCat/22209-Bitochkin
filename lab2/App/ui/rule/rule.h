#ifndef RULE_H
#define RULE_H

#include <QWidget>
#include "../../StateStorage/StateStorage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class rule; }
QT_END_NAMESPACE

class rule : public QWidget {
Q_OBJECT

public:
    explicit rule(QWidget *parent = nullptr);

    ~rule() override;

private:
    Ui::rule *ui;

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
