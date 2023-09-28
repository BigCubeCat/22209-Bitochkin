/********************************************************************************
** Form generated from reading UI file 'neighborhoodselect.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEIGHBORHOODSELECT_H
#define UI_NEIGHBORHOODSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_neighborhoodselect
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;

    void setupUi(QWidget *neighborhoodselect)
    {
        if (neighborhoodselect->objectName().isEmpty())
            neighborhoodselect->setObjectName(QString::fromUtf8("neighborhoodselect"));
        neighborhoodselect->resize(360, 308);
        verticalLayout_2 = new QVBoxLayout(neighborhoodselect);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(neighborhoodselect);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(100, 100));
        tableView->setMaximumSize(QSize(300, 300));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalWidget = new QWidget(neighborhoodselect);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalWidget->setMaximumSize(QSize(300, 16777215));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(horizontalWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(horizontalWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(3);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addWidget(horizontalWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(neighborhoodselect);

        QMetaObject::connectSlotsByName(neighborhoodselect);
    } // setupUi

    void retranslateUi(QWidget *neighborhoodselect)
    {
        neighborhoodselect->setWindowTitle(QCoreApplication::translate("neighborhoodselect", "neighborhoodselect", nullptr));
        label->setText(QCoreApplication::translate("neighborhoodselect", "Degree:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class neighborhoodselect: public Ui_neighborhoodselect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEIGHBORHOODSELECT_H
