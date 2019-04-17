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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLCDNumber *lcdNumber;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_Plus;
    QPushButton *pushButton_CE;
    QPushButton *pushButton_Minus;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_Dot;
    QPushButton *pushButton_Devi;
    QPushButton *pushButton_9;
    QPushButton *pushButton_Multi;
    QPushButton *pushButton_8;
    QPushButton *pushButton_Eq;
    QPushButton *pushButton_7;
    QPushButton *pushButton_0;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(356, 167);
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(9, 9, 109, 23));
        lcdNumber->setDigitCount(10);
        pushButton_1 = new QPushButton(Widget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(9, 40, 30, 25));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(95, 40, 80, 25));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(181, 40, 80, 25));
        pushButton_Plus = new QPushButton(Widget);
        pushButton_Plus->setObjectName(QStringLiteral("pushButton_Plus"));
        pushButton_Plus->setGeometry(QRect(267, 30, 80, 25));
        pushButton_CE = new QPushButton(Widget);
        pushButton_CE->setObjectName(QStringLiteral("pushButton_CE"));
        pushButton_CE->setGeometry(QRect(267, 9, 80, 25));
        pushButton_Minus = new QPushButton(Widget);
        pushButton_Minus->setObjectName(QStringLiteral("pushButton_Minus"));
        pushButton_Minus->setGeometry(QRect(267, 71, 80, 25));
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(180, 71, 80, 25));
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(95, 71, 80, 25));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(9, 71, 80, 25));
        pushButton_Dot = new QPushButton(Widget);
        pushButton_Dot->setObjectName(QStringLiteral("pushButton_Dot"));
        pushButton_Dot->setGeometry(QRect(9, 133, 80, 25));
        pushButton_Devi = new QPushButton(Widget);
        pushButton_Devi->setObjectName(QStringLiteral("pushButton_Devi"));
        pushButton_Devi->setGeometry(QRect(267, 133, 80, 25));
        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(181, 102, 80, 25));
        pushButton_Multi = new QPushButton(Widget);
        pushButton_Multi->setObjectName(QStringLiteral("pushButton_Multi"));
        pushButton_Multi->setGeometry(QRect(267, 102, 80, 25));
        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(95, 102, 80, 25));
        pushButton_Eq = new QPushButton(Widget);
        pushButton_Eq->setObjectName(QStringLiteral("pushButton_Eq"));
        pushButton_Eq->setGeometry(QRect(181, 133, 80, 25));
        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(9, 102, 80, 25));
        pushButton_0 = new QPushButton(Widget);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));
        pushButton_0->setGeometry(QRect(95, 133, 80, 25));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        pushButton_Plus->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        pushButton_CE->setText(QApplication::translate("Widget", "CE", Q_NULLPTR));
        pushButton_Minus->setText(QApplication::translate("Widget", "-", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        pushButton_Dot->setText(QApplication::translate("Widget", ".", Q_NULLPTR));
        pushButton_Devi->setText(QApplication::translate("Widget", "\303\267", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("Widget", "9", Q_NULLPTR));
        pushButton_Multi->setText(QApplication::translate("Widget", "\303\227", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Widget", "8", Q_NULLPTR));
        pushButton_Eq->setText(QApplication::translate("Widget", "=", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Widget", "7", Q_NULLPTR));
        pushButton_0->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
