#include "msg.h"
#include "ui_msg.h"
#include <QMessageBox>
#include <QDebug>

msg::msg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::msg)
{
    ui->setupUi(this);
}

msg::~msg()
{
    delete ui;
}
void msg::on_pushButtonQuestion_clicked()
{
    QMessageBox::question(this, "询问消息框", "你好吗？", QMessageBox::Yes, QMessageBox::No);
}

void msg::on_pushButtonInfo_clicked()
{
    QMessageBox::information(this, "信息消息框", "粤嵌", QMessageBox::Ok);
}

void msg::on_pushButtonWarning_clicked()
{
    QMessageBox::warning(this, "警告消息框", "警告！", QMessageBox::Ok);
}

void msg::on_pushButtonCritical_clicked()
{
    QMessageBox::critical(this, "致命消息框", "内存崩溃！", QMessageBox::Apply, QMessageBox::Accepted);
}

void msg::on_pushButtonQuit_clicked()
{
    this->close();
}
