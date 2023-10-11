/********************************************************************************
** Form generated from reading UI file 'panel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_H
#define UI_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_panel
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *panelLayout;

    void setupUi(QWidget *panel)
    {
        if (panel->objectName().isEmpty())
            panel->setObjectName(QString::fromUtf8("panel"));
        panel->resize(275, 370);
        verticalLayout_2 = new QVBoxLayout(panel);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        panelLayout = new QVBoxLayout();
        panelLayout->setObjectName(QString::fromUtf8("panelLayout"));

        verticalLayout_2->addLayout(panelLayout);


        retranslateUi(panel);

        QMetaObject::connectSlotsByName(panel);
    } // setupUi

    void retranslateUi(QWidget *panel)
    {
        panel->setWindowTitle(QCoreApplication::translate("panel", "panel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class panel: public Ui_panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_H
