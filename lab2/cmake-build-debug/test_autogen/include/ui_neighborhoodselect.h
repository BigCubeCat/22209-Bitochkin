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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_neighborhoodselect
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QWidget *horizontalWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;

    void setupUi(QWidget *neighborhoodselect)
    {
        if (neighborhoodselect->objectName().isEmpty())
            neighborhoodselect->setObjectName(QString::fromUtf8("neighborhoodselect"));
        neighborhoodselect->resize(258, 298);
        verticalLayout_2 = new QVBoxLayout(neighborhoodselect);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        title = new QLabel(neighborhoodselect);
        title->setObjectName(QString::fromUtf8("title"));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(title);

        horizontalWidget = new QWidget(neighborhoodselect);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(horizontalWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(horizontalWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addWidget(horizontalWidget);

        horizontalWidget1 = new QWidget(neighborhoodselect);
        horizontalWidget1->setObjectName(QString::fromUtf8("horizontalWidget1"));
        horizontalWidget1->setMaximumSize(QSize(300, 16777215));
        horizontalLayout = new QHBoxLayout(horizontalWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(horizontalWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(horizontalWidget1);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(3);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addWidget(horizontalWidget1);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(neighborhoodselect);

        QMetaObject::connectSlotsByName(neighborhoodselect);
    } // setupUi

    void retranslateUi(QWidget *neighborhoodselect)
    {
        neighborhoodselect->setWindowTitle(QCoreApplication::translate("neighborhoodselect", "neighborhoodselect", nullptr));
        title->setText(QCoreApplication::translate("neighborhoodselect", "Neighborhood", nullptr));
        label_2->setText(QCoreApplication::translate("neighborhoodselect", "Type:", nullptr));
        comboBox->setCurrentText(QString());
        label->setText(QCoreApplication::translate("neighborhoodselect", "Degree:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class neighborhoodselect: public Ui_neighborhoodselect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEIGHBORHOODSELECT_H
