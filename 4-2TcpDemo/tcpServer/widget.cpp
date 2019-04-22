#include "widget.h"
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    text = new QPlainTextEdit;
    btn  = new QPushButton(tr("启动"));
    layout = new QVBoxLayout(this);

    layout->addWidget(text);
    layout->addWidget(btn);

    isListening = false;

    // 按下按钮之后，启动服务器
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(btnClickSlot()));
}

Widget::~Widget()
{

}

void Widget::newConnection()
{
    if(!server.hasPendingConnections())
        return;

    qDebug() << "[server]有新的连接";

    // 取得第一个在服务器中等待连接的套接字
    socket = server.nextPendingConnection();

    // 为这个套接字将来的数据到达关联槽函数
    connect(socket, SIGNAL(readyRead()), this, SLOT(tcpData()));
}

void Widget::tcpData()
{
    qDebug() << "[server]收到数据";

    QByteArray data = socket->readAll();
    qDebug() << data;

    text->appendPlainText(QString::fromStdString(data.toStdString()));
}

void Widget::btnClickSlot()
{
    if(isListening) // 当前状态：已连接，要断开连接
    {
        server.close();
        btn->setText(tr("启动"));
        isListening = false;
    }
    else // 当前状态：已断开，要启动服务器
    {
        // 建立监听套接字、绑定地址、设置监听状态：
        if(server.listen(QHostAddress("192.168.1.188"), 50003))
        {
            // 将来有新的连接时，自动触发信号newConnection，并调用槽函数
            connect(&server, SIGNAL(newConnection()), this, SLOT(newConnection()));
            btn->setText(tr("断开"));
            isListening = true;
        }
        else
        {
            QMessageBox::information(this, tr("启动服务器失败"), server.errorString(), QMessageBox::Ok);
        }
    }
}
