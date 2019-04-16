/********************************************************************************
** Form generated from reading UI file 'input.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_H
#define UI_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(136, 160);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Sunken);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        label_3 = new QLabel(Form);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 1, 1, 1);

        label_4 = new QLabel(Form);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFrameShape(QFrame::Panel);
        label_4->setFrameShadow(QFrame::Sunken);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 3, 1, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "\345\274\240\344\270\211", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Form", "\344\277\256\346\224\271\345\247\223\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "\347\224\267", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Form", "\344\277\256\346\224\271\346\200\247\345\210\253", Q_NULLPTR));
        label_3->setText(QApplication::translate("Form", "21", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Form", "\344\277\256\346\224\271\345\271\264\351\276\204", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", "68.5", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Form", "\344\277\256\346\224\271\345\210\206\346\225\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_H
