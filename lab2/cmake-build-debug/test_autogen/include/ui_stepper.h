/********************************************************************************
** Form generated from reading UI file 'stepper.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEPPER_H
#define UI_STEPPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stepper
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QWidget *btnWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *speedSlider;

    void setupUi(QWidget *stepper)
    {
        if (stepper->objectName().isEmpty())
            stepper->setObjectName(QString::fromUtf8("stepper"));
        stepper->resize(292, 150);
        verticalLayout_2 = new QVBoxLayout(stepper);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalWidget = new QWidget(stepper);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy);
        verticalWidget->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnWidget = new QWidget(verticalWidget);
        btnWidget->setObjectName(QString::fromUtf8("btnWidget"));
        sizePolicy.setHeightForWidth(btnWidget->sizePolicy().hasHeightForWidth());
        btnWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(btnWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_3 = new QPushButton(btnWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(btnWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(btnWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addWidget(btnWidget);

        horizontalWidget = new QWidget(verticalWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(horizontalWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        speedSlider = new QSlider(horizontalWidget);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        speedSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(speedSlider);


        verticalLayout->addWidget(horizontalWidget);


        verticalLayout_2->addWidget(verticalWidget);


        retranslateUi(stepper);

        QMetaObject::connectSlotsByName(stepper);
    } // setupUi

    void retranslateUi(QWidget *stepper)
    {
        stepper->setWindowTitle(QCoreApplication::translate("stepper", "stepper", nullptr));
        pushButton_3->setText(QCoreApplication::translate("stepper", "stop", nullptr));
        pushButton->setText(QCoreApplication::translate("stepper", "step", nullptr));
        pushButton_2->setText(QCoreApplication::translate("stepper", "run", nullptr));
        label->setText(QCoreApplication::translate("stepper", "speed:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stepper: public Ui_stepper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEPPER_H