#include "Rule.h"

#include <QObject>
#include <QPushButton>
#include <QTextEdit>
#include <iostream>

#include "ui_rule.h"

Rule::Rule(QWidget *parent) : QWidget(parent), ui(new Ui::Rule) {
    ui->setupUi(this);
    QObject::connect(ui->textEdit, &QTextEdit::textChanged, this, &Rule::setB);
    QObject::connect(ui->textEdit_2, &QTextEdit::textChanged, this,
                     &Rule::setS);
    QObject::connect(ui->applyButton, &QPushButton::clicked, this,
                     &Rule::applySlot);
}

Rule::~Rule() {
    delete ui;
}

void Rule::setB() {
    auto txt = ui->textEdit->toPlainText();
    bRuleString = txt.toStdString();
}

void Rule::setS() {
    auto txt = ui->textEdit_2->toPlainText();
    sRuleString = txt.toStdString();
}

void Rule::applySlot() {
    std::cout << bRuleString << " " << sRuleString << "\n";
    auto rules = "B" + bRuleString + "/S" + sRuleString;
    ui->errorMessage->setText("");
    this->update();
    emit emitRules(rules);
}

void Rule::invalidRules() {
    ui->errorMessage->setText("Invalid rules");
    this->update();
}

void Rule::parseTRules(const TRules &newRules) {
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
