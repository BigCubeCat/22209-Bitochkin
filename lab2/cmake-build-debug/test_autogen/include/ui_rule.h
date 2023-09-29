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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rule
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QTextEdit *textEdit;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QWidget *horizontalWidget1;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;

    void setupUi(QWidget *rule)
    {
        if (rule->objectName().isEmpty())
            rule->setObjectName(QString::fromUtf8("rule"));
        rule->resize(400, 334);
        verticalLayout_2 = new QVBoxLayout(rule);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(rule);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalWidget_2 = new QWidget(widget);
        horizontalWidget_2->setObjectName(QString::fromUtf8("horizontalWidget_2"));
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

        horizontalWidget = new QWidget(widget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
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

        horizontalWidget1 = new QWidget(widget);
        horizontalWidget1->setObjectName(QString::fromUtf8("horizontalWidget1"));
        sizePolicy.setHeightForWidth(horizontalWidget1->sizePolicy().hasHeightForWidth());
        horizontalWidget1->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        applyButton = new QPushButton(horizontalWidget1);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout_3->addWidget(applyButton);


        verticalLayout->addWidget(horizontalWidget1);


        verticalLayout_2->addWidget(widget);


        retranslateUi(rule);

        QMetaObject::connectSlotsByName(rule);
    } // setupUi

    void retranslateUi(QWidget *rule)
    {
        rule->setWindowTitle(QCoreApplication::translate("rule", "rule", nullptr));
        label->setText(QCoreApplication::translate("rule", "Birth-rule:", nullptr));
        label_2->setText(QCoreApplication::translate("rule", "Save-rule:", nullptr));
        applyButton->setText(QCoreApplication::translate("rule", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rule: public Ui_rule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULE_H
