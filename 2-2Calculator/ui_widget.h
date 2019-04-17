/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_CE;
    QPushButton *pushButton_Plus;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_Minus;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_Multi;
    QPushButton *pushButton_Dot;
    QPushButton *pushButton_0;
    QPushButton *pushButton_Eq;
    QPushButton *pushButton_Devi;
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(356, 167);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_CE = new QPushButton(Widget);
        pushButton_CE->setObjectName(QStringLiteral("pushButton_CE"));

        gridLayout->addWidget(pushButton_CE, 0, 3, 1, 1);

        pushButton_Plus = new QPushButton(Widget);
        pushButton_Plus->setObjectName(QStringLiteral("pushButton_Plus"));

        gridLayout->addWidget(pushButton_Plus, 1, 3, 2, 1);

        pushButton_1 = new QPushButton(Widget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));

        gridLayout->addWidget(pushButton_1, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 1);

        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 3, 1, 1, 1);

        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 3, 2, 1, 1);

        pushButton_Minus = new QPushButton(Widget);
        pushButton_Minus->setObjectName(QStringLiteral("pushButton_Minus"));

        gridLayout->addWidget(pushButton_Minus, 3, 3, 1, 1);

        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 4, 0, 1, 1);

        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 4, 1, 1, 1);

        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 4, 2, 1, 1);

        pushButton_Multi = new QPushButton(Widget);
        pushButton_Multi->setObjectName(QStringLiteral("pushButton_Multi"));

        gridLayout->addWidget(pushButton_Multi, 4, 3, 1, 1);

        pushButton_Dot = new QPushButton(Widget);
        pushButton_Dot->setObjectName(QStringLiteral("pushButton_Dot"));

        gridLayout->addWidget(pushButton_Dot, 5, 0, 1, 1);

        pushButton_0 = new QPushButton(Widget);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));

        gridLayout->addWidget(pushButton_0, 5, 1, 1, 1);

        pushButton_Eq = new QPushButton(Widget);
        pushButton_Eq->setObjectName(QStringLiteral("pushButton_Eq"));

        gridLayout->addWidget(pushButton_Eq, 5, 2, 1, 1);

        pushButton_Devi = new QPushButton(Widget);
        pushButton_Devi->setObjectName(QStringLiteral("pushButton_Devi"));

        gridLayout->addWidget(pushButton_Devi, 5, 3, 1, 1);

        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setDigitCount(10);

        gridLayout->addWidget(lcdNumber, 0, 0, 2, 3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButton_CE->setText(QApplication::translate("Widget", "CE", Q_NULLPTR));
        pushButton_Plus->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
        pushButton_Minus->setText(QApplication::translate("Widget", "-", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Widget", "7", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Widget", "8", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("Widget", "9", Q_NULLPTR));
        pushButton_Multi->setText(QApplication::translate("Widget", "\303\227", Q_NULLPTR));
        pushButton_Dot->setText(QApplication::translate("Widget", ".", Q_NULLPTR));
        pushButton_0->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
        pushButton_Eq->setText(QApplication::translate("Widget", "=", Q_NULLPTR));
        pushButton_Devi->setText(QApplication::translate("Widget", "\303\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
