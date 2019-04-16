/********************************************************************************
** Form generated from reading UI file 'inputdiglog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIGLOG_H
#define UI_INPUTDIGLOG_H

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

class Ui_inputDiglog
{
public:
    QGridLayout *gridLayout;
    QLabel *labelName;
    QPushButton *pushButton_ChangeName;
    QLabel *labelSex;
    QPushButton *pushButton_ChangeSex;
    QLabel *labelAge;
    QPushButton *pushButton_ChangeAge;
    QLabel *labelScore;
    QPushButton *pushButton_ChangeScore;

    void setupUi(QWidget *inputDiglog)
    {
        if (inputDiglog->objectName().isEmpty())
            inputDiglog->setObjectName(QStringLiteral("inputDiglog"));
        inputDiglog->resize(138, 160);
        gridLayout = new QGridLayout(inputDiglog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelName = new QLabel(inputDiglog);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setFrameShape(QFrame::Panel);
        labelName->setFrameShadow(QFrame::Sunken);
        labelName->setLineWidth(2);
        labelName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelName, 0, 0, 1, 1);

        pushButton_ChangeName = new QPushButton(inputDiglog);
        pushButton_ChangeName->setObjectName(QStringLiteral("pushButton_ChangeName"));

        gridLayout->addWidget(pushButton_ChangeName, 0, 1, 1, 1);

        labelSex = new QLabel(inputDiglog);
        labelSex->setObjectName(QStringLiteral("labelSex"));
        labelSex->setFrameShape(QFrame::Panel);
        labelSex->setFrameShadow(QFrame::Sunken);
        labelSex->setLineWidth(2);
        labelSex->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelSex, 1, 0, 1, 1);

        pushButton_ChangeSex = new QPushButton(inputDiglog);
        pushButton_ChangeSex->setObjectName(QStringLiteral("pushButton_ChangeSex"));

        gridLayout->addWidget(pushButton_ChangeSex, 1, 1, 1, 1);

        labelAge = new QLabel(inputDiglog);
        labelAge->setObjectName(QStringLiteral("labelAge"));
        labelAge->setFrameShape(QFrame::Panel);
        labelAge->setFrameShadow(QFrame::Sunken);
        labelAge->setLineWidth(2);
        labelAge->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelAge, 2, 0, 1, 1);

        pushButton_ChangeAge = new QPushButton(inputDiglog);
        pushButton_ChangeAge->setObjectName(QStringLiteral("pushButton_ChangeAge"));

        gridLayout->addWidget(pushButton_ChangeAge, 2, 1, 1, 1);

        labelScore = new QLabel(inputDiglog);
        labelScore->setObjectName(QStringLiteral("labelScore"));
        labelScore->setFrameShape(QFrame::Panel);
        labelScore->setFrameShadow(QFrame::Sunken);
        labelScore->setLineWidth(2);
        labelScore->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelScore, 3, 0, 1, 1);

        pushButton_ChangeScore = new QPushButton(inputDiglog);
        pushButton_ChangeScore->setObjectName(QStringLiteral("pushButton_ChangeScore"));

        gridLayout->addWidget(pushButton_ChangeScore, 3, 1, 1, 1);


        retranslateUi(inputDiglog);

        QMetaObject::connectSlotsByName(inputDiglog);
    } // setupUi

    void retranslateUi(QWidget *inputDiglog)
    {
        inputDiglog->setWindowTitle(QApplication::translate("inputDiglog", "Form", Q_NULLPTR));
        labelName->setText(QApplication::translate("inputDiglog", "\345\274\240\344\270\211", Q_NULLPTR));
        pushButton_ChangeName->setText(QApplication::translate("inputDiglog", "\344\277\256\346\224\271\345\247\223\345\220\215", Q_NULLPTR));
        labelSex->setText(QApplication::translate("inputDiglog", "\347\224\267", Q_NULLPTR));
        pushButton_ChangeSex->setText(QApplication::translate("inputDiglog", "\344\277\256\346\224\271\346\200\247\345\210\253", Q_NULLPTR));
        labelAge->setText(QApplication::translate("inputDiglog", "21", Q_NULLPTR));
        pushButton_ChangeAge->setText(QApplication::translate("inputDiglog", "\344\277\256\346\224\271\345\271\264\351\276\204", Q_NULLPTR));
        labelScore->setText(QApplication::translate("inputDiglog", "89.5", Q_NULLPTR));
        pushButton_ChangeScore->setText(QApplication::translate("inputDiglog", "\344\277\256\346\224\271\345\210\206\346\225\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class inputDiglog: public Ui_inputDiglog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIGLOG_H
