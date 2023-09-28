/********************************************************************************
** Form generated from reading UI file 'rule.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULE_H
#define UI_RULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rule
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *birthError;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QLabel *label_3;

    void setupUi(QWidget *rule)
    {
        if (rule->objectName().isEmpty())
            rule->setObjectName(QString::fromUtf8("rule"));
        rule->resize(400, 334);
        verticalLayout_2 = new QVBoxLayout(rule);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalWidget_2 = new QWidget(rule);
        horizontalWidget_2->setObjectName(QString::fromUtf8("horizontalWidget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalWidget_2->sizePolicy().hasHeightForWidth());
        horizontalWidget_2->setSizePolicy(sizePolicy);
        horizontalWidget_2->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(horizontalWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        textEdit = new QTextEdit(horizontalWidget_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_2->addWidget(textEdit);


        verticalLayout->addWidget(horizontalWidget_2);

        birthError = new QLabel(rule);
        birthError->setObjectName(QString::fromUtf8("birthError"));
        birthError->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(birthError);

        horizontalWidget = new QWidget(rule);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalWidget->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(horizontalWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        textEdit_2 = new QTextEdit(horizontalWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(textEdit_2);


        verticalLayout->addWidget(horizontalWidget);

        label_3 = new QLabel(rule);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(label_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(rule);

        QMetaObject::connectSlotsByName(rule);
    } // setupUi

    void retranslateUi(QWidget *rule)
    {
        rule->setWindowTitle(QCoreApplication::translate("rule", "rule", nullptr));
        label->setText(QCoreApplication::translate("rule", "Birth-rule:", nullptr));
        birthError->setText(QString());
        label_2->setText(QCoreApplication::translate("rule", "Save-rule:", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class rule: public Ui_rule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULE_H
