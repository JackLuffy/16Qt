/********************************************************************************
** Form generated from reading UI file 'msg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSG_H
#define UI_MSG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_msg
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonQuestion;
    QPushButton *pushButtonInfo;
    QPushButton *pushButtonWarning;
    QPushButton *pushButtonCritical;
    QPushButton *pushButtonAbout;
    QPushButton *pushButtonQuit;

    void setupUi(QWidget *msg)
    {
        if (msg->objectName().isEmpty())
            msg->setObjectName(QStringLiteral("msg"));
        msg->resize(101, 234);
        verticalLayout = new QVBoxLayout(msg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButtonQuestion = new QPushButton(msg);
        pushButtonQuestion->setObjectName(QStringLiteral("pushButtonQuestion"));

        verticalLayout->addWidget(pushButtonQuestion);

        pushButtonInfo = new QPushButton(msg);
        pushButtonInfo->setObjectName(QStringLiteral("pushButtonInfo"));

        verticalLayout->addWidget(pushButtonInfo);

        pushButtonWarning = new QPushButton(msg);
        pushButtonWarning->setObjectName(QStringLiteral("pushButtonWarning"));

        verticalLayout->addWidget(pushButtonWarning);

        pushButtonCritical = new QPushButton(msg);
        pushButtonCritical->setObjectName(QStringLiteral("pushButtonCritical"));

        verticalLayout->addWidget(pushButtonCritical);

        pushButtonAbout = new QPushButton(msg);
        pushButtonAbout->setObjectName(QStringLiteral("pushButtonAbout"));

        verticalLayout->addWidget(pushButtonAbout);

        pushButtonQuit = new QPushButton(msg);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));
        QIcon icon;
        icon.addFile(QStringLiteral("../Desktop/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonQuit->setIcon(icon);

        verticalLayout->addWidget(pushButtonQuit);


        retranslateUi(msg);

        QMetaObject::connectSlotsByName(msg);
    } // setupUi

    void retranslateUi(QWidget *msg)
    {
        msg->setWindowTitle(QApplication::translate("msg", "Form", Q_NULLPTR));
        pushButtonQuestion->setText(QApplication::translate("msg", "\350\257\242\351\227\256\346\266\210\346\201\257\346\241\206", Q_NULLPTR));
        pushButtonInfo->setText(QApplication::translate("msg", "\344\277\241\346\201\257\346\266\210\346\201\257\346\241\206", Q_NULLPTR));
        pushButtonWarning->setText(QApplication::translate("msg", "\350\255\246\345\221\212\346\266\210\346\201\257\346\241\206", Q_NULLPTR));
        pushButtonCritical->setText(QApplication::translate("msg", "\350\207\264\345\221\275\346\266\210\346\201\257\346\241\206", Q_NULLPTR));
        pushButtonAbout->setText(QApplication::translate("msg", "\345\205\263\344\272\216\346\266\210\346\201\257\346\241\206", Q_NULLPTR));
        pushButtonQuit->setText(QApplication::translate("msg", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class msg: public Ui_msg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSG_H
