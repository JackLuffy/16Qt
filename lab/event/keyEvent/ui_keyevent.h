/********************************************************************************
** Form generated from reading UI file 'keyevent.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYEVENT_H
#define UI_KEYEVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keyEvent
{
public:

    void setupUi(QWidget *keyEvent)
    {
        if (keyEvent->objectName().isEmpty())
            keyEvent->setObjectName(QStringLiteral("keyEvent"));
        keyEvent->resize(400, 300);

        retranslateUi(keyEvent);

        QMetaObject::connectSlotsByName(keyEvent);
    } // setupUi

    void retranslateUi(QWidget *keyEvent)
    {
        keyEvent->setWindowTitle(QApplication::translate("keyEvent", "keyEvent", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class keyEvent: public Ui_keyEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYEVENT_H
