#include "rule.h"
#include "ui_rule.h"

#include <QPushButton>
#include <QTextEdit>
#include <QObject>

#include <iostream>

rule::rule(QWidget *parent, StateStorage *store) :
        QWidget(parent), ui(new Ui::rule), store(store) {
    ui->setupUi(this);
    QObject::connect(ui->textEdit, &QTextEdit::textChanged, this, &rule::setB);
    QObject::connect(ui->textEdit_2, &QTextEdit::textChanged, this, &rule::setS);
    QObject::connect(ui->applyButton, &QPushButton::clicked, this, &rule::applySlot);

    QObject::connect(this, &rule::emitRules, this->store, &StateStorage::setRules);
    QObject::connect(this->store, &StateStorage::invalidRule, this, &rule::invalidRules);
}

rule::~rule() {
    delete ui;
}

void rule::setB() {
    auto txt = ui->textEdit->toPlainText();
    bRuleString = txt.toStdString();
}

void rule::setS() {
    auto txt = ui->textEdit_2->toPlainText();
    sRuleString = txt.toStdString();
}

void rule::applySlot() {
    std::cout << bRuleString << " " << sRuleString << "\n";
    auto rules = "B" + bRuleString + "/S" + sRuleString;
    ui->errorMessage->setText("");
    this->update();
    emit emitRules(rules);
}

void rule::invalidRules() {
    ui->errorMessage->setText("Invalid rules");
    this->update();
}
