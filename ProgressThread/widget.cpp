#include "widget.h"
#include "ui_widget.h"
#include <unistd.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);
    ui->progressBar->setRange(0, 100);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(progress()));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::progress()
{
    if(ui->pushButton->text() == "开始")
    {
        ui->pushButton->setText("取消");

        // 实例化线程工人，顺带穿必要的参数给他
        worker = new Worker(ui->progressBar, 0, ui->progressBar->maximum());

        // 启动一条独立的线程，去指定其run函数
        worker->start();
    }

    else if(ui->pushButton->text() == "取消")
    {
        // 终止线程工人
        worker->terminate();
        worker->wait();

        ui->pushButton->setText("开始");
        ui->progressBar->setValue(0);
    }
}

