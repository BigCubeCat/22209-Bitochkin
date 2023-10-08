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

    QObject::connect(this->store, &StateStorage::updateRules, this, &rule::parseTRules);
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

void rule::parseTRules(const TRules & newRules) {
    std::string bText = "";
    std::string sText = "";
    for (size_t i = 0; i < newRules.birthRule.size(); ++i) {
        bText += std::to_string(newRules.birthRule[i]);
        if (i < newRules.birthRule.size() - 1) {
            bText += ',';
        }
    }
    for (size_t i = 0; i < newRules.saveRule.size(); ++i) {
        sText += std::to_string(newRules.saveRule[i]);
        if (i < newRules.saveRule.size() - 1) {
            sText += ',';
        }
    }
    ui->textEdit->setText(QString::fromStdString(bText));
    ui->textEdit_2->setText(QString::fromStdString(sText));
}
