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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_file;
    QLineEdit *lineEdit_file;
    QPushButton *pushButton_color;
    QFrame *frame;
    QPushButton *pushButton_font;
    QLineEdit *lineEdit_font;
    QPushButton *pushButton_input;
    QPushButton *pushButton_msg;
    QPushButton *pushButton_custom;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(294, 197);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_file = new QPushButton(Widget);
        pushButton_file->setObjectName(QStringLiteral("pushButton_file"));

        gridLayout->addWidget(pushButton_file, 0, 0, 1, 1);

        lineEdit_file = new QLineEdit(Widget);
        lineEdit_file->setObjectName(QStringLiteral("lineEdit_file"));

        gridLayout->addWidget(lineEdit_file, 0, 1, 1, 1);

        pushButton_color = new QPushButton(Widget);
        pushButton_color->setObjectName(QStringLiteral("pushButton_color"));

        gridLayout->addWidget(pushButton_color, 1, 0, 1, 1);

        frame = new QFrame(Widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 1, 1, 1, 1);

        pushButton_font = new QPushButton(Widget);
        pushButton_font->setObjectName(QStringLiteral("pushButton_font"));

        gridLayout->addWidget(pushButton_font, 2, 0, 1, 1);

        lineEdit_font = new QLineEdit(Widget);
        lineEdit_font->setObjectName(QStringLiteral("lineEdit_font"));
        lineEdit_font->setEnabled(true);

        gridLayout->addWidget(lineEdit_font, 2, 1, 1, 1);

        pushButton_input = new QPushButton(Widget);
        pushButton_input->setObjectName(QStringLiteral("pushButton_input"));

        gridLayout->addWidget(pushButton_input, 3, 0, 1, 1);

        pushButton_msg = new QPushButton(Widget);
        pushButton_msg->setObjectName(QStringLiteral("pushButton_msg"));

        gridLayout->addWidget(pushButton_msg, 3, 1, 1, 1);

        pushButton_custom = new QPushButton(Widget);
        pushButton_custom->setObjectName(QStringLiteral("pushButton_custom"));

        gridLayout->addWidget(pushButton_custom, 4, 0, 1, 1);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Sunken);
        label->setLineWidth(1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 4, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButton_file->setText(QApplication::translate("Widget", "\346\226\207\344\273\266\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        pushButton_color->setText(QApplication::translate("Widget", "\351\242\234\350\211\262\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        pushButton_font->setText(QApplication::translate("Widget", "\345\255\227\344\275\223\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        lineEdit_font->setText(QApplication::translate("Widget", "\346\234\210\350\220\275\344\271\214\345\225\274\351\234\234\346\273\241\345\244\251", Q_NULLPTR));
        pushButton_input->setText(QApplication::translate("Widget", "\346\240\207\345\207\206\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        pushButton_msg->setText(QApplication::translate("Widget", "\346\240\207\345\207\206\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        pushButton_custom->setText(QApplication::translate("Widget", "\350\207\252\345\256\232\344\271\211\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\347\224\237\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
