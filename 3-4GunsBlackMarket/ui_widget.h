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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTabWidget *tabWidget;
    QWidget *tab1_2;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_typeSale;
    QLineEdit *lineEditPriceTotal;
    QLabel *label_13;
    QLabel *labelRemain;
    QPushButton *pushButton_2;
    QSpinBox *spinBoxBuyAmount;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_11;
    QLineEdit *lineEditPriecPerEach;
    QLabel *label_12;
    QLabel *label_9;
    QLabel *label_8;
    QComboBox *comboBox_name;
    QLabel *label_10;
    QWidget *tab2_2;
    QGridLayout *gridLayout_4;
    QLabel *label_19;
    QComboBox *comboBoxTypeIncome;
    QLabel *label_20;
    QComboBox *comboBoxNameIncome;
    QLabel *label_21;
    QLineEdit *lineEditPriceIncome;
    QLabel *label_22;
    QLineEdit *lineEditAmountIncome;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_4;
    QTableView *tableView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(658, 434);
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 310, 640, 114));
        tab1_2 = new QWidget();
        tab1_2->setObjectName(QStringLiteral("tab1_2"));
        gridLayout_2 = new QGridLayout(tab1_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        comboBox_typeSale = new QComboBox(tab1_2);
        comboBox_typeSale->setObjectName(QStringLiteral("comboBox_typeSale"));

        gridLayout_2->addWidget(comboBox_typeSale, 0, 1, 1, 1);

        lineEditPriceTotal = new QLineEdit(tab1_2);
        lineEditPriceTotal->setObjectName(QStringLiteral("lineEditPriceTotal"));

        gridLayout_2->addWidget(lineEditPriceTotal, 1, 3, 1, 1);

        label_13 = new QLabel(tab1_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 1, 4, 1, 1);

        labelRemain = new QLabel(tab1_2);
        labelRemain->setObjectName(QStringLiteral("labelRemain"));
        labelRemain->setFrameShape(QFrame::Panel);
        labelRemain->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(labelRemain, 1, 5, 1, 1);

        pushButton_2 = new QPushButton(tab1_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 6, 1, 1);

        spinBoxBuyAmount = new QSpinBox(tab1_2);
        spinBoxBuyAmount->setObjectName(QStringLiteral("spinBoxBuyAmount"));

        gridLayout_2->addWidget(spinBoxBuyAmount, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 6, 1, 1);

        label_11 = new QLabel(tab1_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 1, 0, 1, 1);

        lineEditPriecPerEach = new QLineEdit(tab1_2);
        lineEditPriecPerEach->setObjectName(QStringLiteral("lineEditPriecPerEach"));

        gridLayout_2->addWidget(lineEditPriecPerEach, 1, 1, 1, 1);

        label_12 = new QLabel(tab1_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 1, 2, 1, 1);

        label_9 = new QLabel(tab1_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 2, 1, 1);

        label_8 = new QLabel(tab1_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        comboBox_name = new QComboBox(tab1_2);
        comboBox_name->setObjectName(QStringLiteral("comboBox_name"));

        gridLayout_2->addWidget(comboBox_name, 0, 3, 1, 1);

        label_10 = new QLabel(tab1_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 0, 4, 1, 1);

        tabWidget->addTab(tab1_2, QString());
        tab2_2 = new QWidget();
        tab2_2->setObjectName(QStringLiteral("tab2_2"));
        gridLayout_4 = new QGridLayout(tab2_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_19 = new QLabel(tab2_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_4->addWidget(label_19, 0, 0, 1, 1);

        comboBoxTypeIncome = new QComboBox(tab2_2);
        comboBoxTypeIncome->setObjectName(QStringLiteral("comboBoxTypeIncome"));

        gridLayout_4->addWidget(comboBoxTypeIncome, 0, 1, 1, 1);

        label_20 = new QLabel(tab2_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_4->addWidget(label_20, 0, 2, 1, 1);

        comboBoxNameIncome = new QComboBox(tab2_2);
        comboBoxNameIncome->setObjectName(QStringLiteral("comboBoxNameIncome"));

        gridLayout_4->addWidget(comboBoxNameIncome, 0, 3, 1, 1);

        label_21 = new QLabel(tab2_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_4->addWidget(label_21, 0, 4, 1, 1);

        lineEditPriceIncome = new QLineEdit(tab2_2);
        lineEditPriceIncome->setObjectName(QStringLiteral("lineEditPriceIncome"));

        gridLayout_4->addWidget(lineEditPriceIncome, 0, 5, 1, 1);

        label_22 = new QLabel(tab2_2);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_4->addWidget(label_22, 0, 6, 1, 1);

        lineEditAmountIncome = new QLineEdit(tab2_2);
        lineEditAmountIncome->setObjectName(QStringLiteral("lineEditAmountIncome"));

        gridLayout_4->addWidget(lineEditAmountIncome, 0, 7, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(467, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 1, 0, 1, 7);

        pushButton_4 = new QPushButton(tab2_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_4->addWidget(pushButton_4, 1, 7, 1, 1);

        tabWidget->addTab(tab2_2, QString());
        tableView = new QTableView(Widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(9, 9, 641, 291));

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_13->setText(QApplication::translate("Widget", "\345\272\223\345\255\230", Q_NULLPTR));
        labelRemain->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "\346\217\220\344\272\244\350\256\242\345\215\225", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "\345\215\225\344\273\267", Q_NULLPTR));
        label_12->setText(QApplication::translate("Widget", "\346\200\273\344\273\267", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "\345\220\215\347\247\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "\347\261\273\345\210\253", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "\350\264\255\344\271\260\346\225\260\351\207\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1_2), QApplication::translate("Widget", "\351\224\200\345\224\256", Q_NULLPTR));
        label_19->setText(QApplication::translate("Widget", "\347\261\273\345\210\253", Q_NULLPTR));
        label_20->setText(QApplication::translate("Widget", "\345\236\213\345\217\267", Q_NULLPTR));
        label_21->setText(QApplication::translate("Widget", "\344\273\267\346\240\274", Q_NULLPTR));
        label_22->setText(QApplication::translate("Widget", "\346\225\260\351\207\217", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2_2), QApplication::translate("Widget", "\346\226\260\350\264\247\345\205\245\345\272\223", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
