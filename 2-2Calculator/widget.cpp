#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setBtnSize(30, 20);
    setBtnMinimumSize(30, 20);

    ui->lcdNumber->setDigitCount(10);
    ui->lcdNumber->setPalette(QPalette(QColor(Qt::blue)));
    ui->lcdNumber->setMinimumSize(120, 30);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(ui->lcdNumber,      0, 0, 1, 3);
    mainLayout->addWidget(ui->pushButton_CE,  0, 3, 1, 1);

    mainLayout->addWidget(ui->pushButton_1,   1, 0, 1, 1);
    mainLayout->addWidget(ui->pushButton_2,   1, 1, 1, 1);
    mainLayout->addWidget(ui->pushButton_3,   1, 2, 1, 1);
    mainLayout->addWidget(ui->pushButton_Plus,1, 3, 1, 1);

    mainLayout->addWidget(ui->pushButton_4,    2, 0, 1, 1);
    mainLayout->addWidget(ui->pushButton_5,    2, 1, 1, 1);
    mainLayout->addWidget(ui->pushButton_6,    2, 2, 1, 1);
    mainLayout->addWidget(ui->pushButton_Minus,2, 3, 1, 1);

    mainLayout->addWidget(ui->pushButton_7,    3, 0, 1, 1);
    mainLayout->addWidget(ui->pushButton_8,    3, 1, 1, 1);
    mainLayout->addWidget(ui->pushButton_9,    3, 2, 1, 1);
    mainLayout->addWidget(ui->pushButton_Multi,3, 3, 1, 1);

    mainLayout->addWidget(ui->pushButton_Dot,  4, 0, 1, 1);
    mainLayout->addWidget(ui->pushButton_0,    4, 1, 1, 1);
    mainLayout->addWidget(ui->pushButton_Eq,   4, 2, 1, 1);
    mainLayout->addWidget(ui->pushButton_Devi, 4, 3, 1, 1);

    this->resize(1,1);

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
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setBtnSize(int w, int h)
{
    ui->pushButton_1->resize(w, h);
    ui->pushButton_2->resize(w, h);
    ui->pushButton_3->resize(w, h);
    ui->pushButton_4->resize(w, h);
    ui->pushButton_5->resize(w, h);
    ui->pushButton_6->resize(w, h);
    ui->pushButton_7->resize(w, h);
    ui->pushButton_8->resize(w, h);
    ui->pushButton_9->resize(w, h);
    ui->pushButton_0->resize(w, h);
    ui->pushButton_Plus->resize(w, h);
    ui->pushButton_Minus->resize(w, h);
    ui->pushButton_Multi->resize(w, h);
    ui->pushButton_Devi->resize(w, h);
    ui->pushButton_Dot->resize(w, h);
    ui->pushButton_Eq->resize(w, h);
    ui->pushButton_CE->resize(w, h);
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
    if(btnId == 16)
    {
        qDebug() << "计算结果:" << firstVal << "," << op << "," << secondVal;
        switch (op) {
        case 10:
            ui->lcdNumber->display(firstVal + secondVal);
            break;
        case 11:
            ui->lcdNumber->display(firstVal - secondVal);
            break;
        case 12:
            ui->lcdNumber->display(firstVal * secondVal);
            break;
        case 13:
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
