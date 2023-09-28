#ifndef RULE_H
#define RULE_H

#include <QWidget>


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
};

#endif
