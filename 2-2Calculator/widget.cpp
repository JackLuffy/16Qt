#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置按键最小尺寸
    setBtnMinimumSize(30, 20);

    // 设置LCD数位、颜色和大小
    ui->lcdNumber->setDigitCount(10);
    ui->lcdNumber->setPalette(QPalette(QColor(Qt::black)));
    ui->lcdNumber->setMinimumSize(120, 30);

    // 设置按键组
    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->pushButton_0, 0);
    btnGroup->addButton(ui->pushButton_1, 1);
    btnGroup->addButton(ui->pushButton_2, 2);
    btnGroup->addButton(ui->pushButton_3, 3);
    btnGroup->addButton(ui->pushButton_4, 4);
    btnGroup->addButton(ui->pushButton_5, 5);
    btnGroup->addButton(ui->pushButton_6, 6);
    btnGroup->addButton(ui->pushButton_7, 7);
    btnGroup->addButton(ui->pushButton_8, 8);
    btnGroup->addButton(ui->pushButton_9, 9);

    btnGroup->addButton(ui->pushButton_Plus, 10);
    btnGroup->addButton(ui->pushButton_Minus,11);
    btnGroup->addButton(ui->pushButton_Multi,12);
    btnGroup->addButton(ui->pushButton_Devi, 13);

    btnGroup->addButton(ui->pushButton_CE, 14);
    btnGroup->addButton(ui->pushButton_Dot,15);
    btnGroup->addButton(ui->pushButton_Eq, 16);

    connect(btnGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(cal(int)));

    this->setGeometry(300, 300, 1, 1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setBtnMinimumSize(int w, int h)
{
    ui->pushButton_1->setMinimumSize(w, h);
    ui->pushButton_2->setMinimumSize(w, h);
    ui->pushButton_3->setMinimumSize(w, h);
    ui->pushButton_4->setMinimumSize(w, h);
    ui->pushButton_5->setMinimumSize(w, h);
    ui->pushButton_6->setMinimumSize(w, h);
    ui->pushButton_7->setMinimumSize(w, h);
    ui->pushButton_8->setMinimumSize(w, h);
    ui->pushButton_9->setMinimumSize(w, h);
    ui->pushButton_0->setMinimumSize(w, h);
    ui->pushButton_Plus->setMinimumSize(w, h);
    ui->pushButton_Minus->setMinimumSize(w, h);
    ui->pushButton_Multi->setMinimumSize(w, h);
    ui->pushButton_Devi->setMinimumSize(w, h);
    ui->pushButton_Dot->setMinimumSize(w, h);
    ui->pushButton_Eq->setMinimumSize(w, h);
    ui->pushButton_CE->setMinimumSize(w, h);
}

void Widget::cal(int btnId)
{
    static float firstVal;
    static float secondVal;

    static bool first = true;
    static int  op;

    // 计算结果
    if(btnId == Widget::EQ)
    {
        switch (op) {
        case Widget::PLUS:
            ui->lcdNumber->display(firstVal + secondVal);
            break;
        case Widget::MINUS:
            ui->lcdNumber->display(firstVal - secondVal);
            break;
        case Widget::MULTI:
            ui->lcdNumber->display(firstVal * secondVal);
            break;
        case Widget::DIVI:
            ui->lcdNumber->display(firstVal / secondVal);
            break;
        }

        first = true;
        firstVal = 0;
        secondVal = 0;
        return;
    }

    // 输入第一个操作数
    if(btnId >= 0 && btnId <= 9 && first)
    {
        ui->lcdNumber->display(firstVal*10+btnId);
        firstVal = ui->lcdNumber->value();
        return;
    }

    // 输入操作符
    else if(first)
    {
        first = false;
        op = btnId;
        return;
    }

    // 输入第二个操作数
    else
    {
        ui->lcdNumber->display(secondVal*10+btnId);
        secondVal = ui->lcdNumber->value();
    }
}


void Widget::keyPressEvent(QKeyEvent *kpe)
{
    qDebug() << hex << "0x" << kpe->key();

    if(kpe->modifiers() == Qt::ShiftModifier)
    {
        switch(kpe->key())
        {
        case Qt::Key_Plus:
            btnGroup->buttonClicked(PLUS);
            break;
        case Qt::Key_Asterisk:
            btnGroup->buttonClicked(MULTI);
            break;
        }
        return;
    }
    switch(kpe->key())
    {
    case Qt::Key_0:
        btnGroup->buttonClicked(0);
        break;
    case Qt::Key_1:
        btnGroup->buttonClicked(1);
        break;
    case Qt::Key_2:
        btnGroup->buttonClicked(2);
        break;
    case Qt::Key_3:
        btnGroup->buttonClicked(3);
        break;
    case Qt::Key_4:
        btnGroup->buttonClicked(4);
        break;
    case Qt::Key_5:
        btnGroup->buttonClicked(5);
        break;
    case Qt::Key_6:
        btnGroup->buttonClicked(6);
        break;
    case Qt::Key_7:
        btnGroup->buttonClicked(7);
        break;
    case Qt::Key_8:
        btnGroup->buttonClicked(8);
        break;
    case Qt::Key_9:
        btnGroup->buttonClicked(9);
        break;
    case Qt::Key_Equal:
    case Qt::Key_Return:
        btnGroup->buttonClicked(EQ);
        break;
    case Qt::Key_Minus:
        btnGroup->buttonClicked(MINUS);
        break;
    case Qt::Key_Slash:
        btnGroup->buttonClicked(DIVI);
        break;
    }
}
