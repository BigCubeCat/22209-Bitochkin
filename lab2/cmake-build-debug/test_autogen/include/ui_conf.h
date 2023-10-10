/********************************************************************************
** Form generated from reading UI file 'conf.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONF_H
#define UI_CONF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_conf
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *aliveButton;
    QPushButton *diedButton;
    QPushButton *borderButton;
    QHBoxLayout *horizontalLayout_2;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpinBox *cellSizeSpin;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QSpinBox *gapSizeSpin;

    void setupUi(QWidget *conf)
    {
        if (conf->objectName().isEmpty())
            conf->setObjectName(QString::fromUtf8("conf"));
        conf->resize(400, 300);
        verticalLayout = new QVBoxLayout(conf);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(conf);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(16);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        aliveButton = new QPushButton(conf);
        aliveButton->setObjectName(QString::fromUtf8("aliveButton"));

        horizontalLayout->addWidget(aliveButton);

        diedButton = new QPushButton(conf);
        diedButton->setObjectName(QString::fromUtf8("diedButton"));

        horizontalLayout->addWidget(diedButton);

        borderButton = new QPushButton(conf);
        borderButton->setObjectName(QString::fromUtf8("borderButton"));

        horizontalLayout->addWidget(borderButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalWidget = new QWidget(conf);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(verticalWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(verticalWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        cellSizeSpin = new QSpinBox(verticalWidget);
        cellSizeSpin->setObjectName(QString::fromUtf8("cellSizeSpin"));
        cellSizeSpin->setMinimum(1);
        cellSizeSpin->setMaximum(200);
        cellSizeSpin->setValue(10);

        verticalLayout_2->addWidget(cellSizeSpin);


        horizontalLayout_2->addWidget(verticalWidget);

        verticalWidget_2 = new QWidget(conf);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        sizePolicy.setHeightForWidth(verticalWidget_2->sizePolicy().hasHeightForWidth());
        verticalWidget_2->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(verticalWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        gapSizeSpin = new QSpinBox(verticalWidget_2);
        gapSizeSpin->setObjectName(QString::fromUtf8("gapSizeSpin"));
        gapSizeSpin->setMaximum(5);
        gapSizeSpin->setValue(1);

        verticalLayout_3->addWidget(gapSizeSpin);


        horizontalLayout_2->addWidget(verticalWidget_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(conf);

        QMetaObject::connectSlotsByName(conf);
    } // setupUi

    void retranslateUi(QWidget *conf)
    {
        conf->setWindowTitle(QCoreApplication::translate("conf", "conf", nullptr));
        label_3->setText(QCoreApplication::translate("conf", "Settings", nullptr));
        aliveButton->setText(QCoreApplication::translate("conf", "Alive", nullptr));
        diedButton->setText(QCoreApplication::translate("conf", "Empty", nullptr));
        borderButton->setText(QCoreApplication::translate("conf", "Border", nullptr));
        label->setText(QCoreApplication::translate("conf", "Cell size", nullptr));
        label_2->setText(QCoreApplication::translate("conf", "Gap size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class conf: public Ui_conf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONF_H
