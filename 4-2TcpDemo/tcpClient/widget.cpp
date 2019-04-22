#include "widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    lineEdit = new QLineEdit;
     btn = new QPushButton(tr("发送"));

     layout = new QHBoxLayout(this);
     layout->addWidget(lineEdit);
     layout->addWidget(btn);

     // 创建一个tcp套接字
     socket = new QTcpSocket(this);

     // 连接指定服务器
     socket->connectToHost("192.168.1.188", 50003);

     // 等待1秒钟，等三次握手连接完成
     if(socket->waitForConnected(1000))
         qDebug() << "[客户端]连接成功";


     // 信号与槽: 点击发送按钮后，发送输入栏中的消息给服务器
     connect(btn, SIGNAL(clicked(bool)), this, SLOT(sendTcpData()));
}

Widget::~Widget()
{

}

void Widget::sendTcpData()
{
    // 将输入栏中的消息，通过套接字发出去
    int n = socket->write(lineEdit->text().toStdString().data());

    if(n == -1)
    {
        QMessageBox::information(this, tr("发送失败"), socket->errorString(), QMessageBox::Ok);
    }
    else
    {
        qDebug() << "已发送" << n << "个字节";
        lineEdit->clear();
    }
}
