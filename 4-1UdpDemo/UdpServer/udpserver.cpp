#include "udpserver.h"
#include <QHostAddress>

UdpServer::UdpServer(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle("UDP Server");

    TextLineEdit = new QLineEdit(this);
    StartBtn = new QPushButton("开始广播",this);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(TextLineEdit);
    mainLayout->addWidget(StartBtn);

    port = 50001;
    isStarted=false;

    // 点击按钮，开始广播
    udpSocket = new QUdpSocket(this);
    connect(StartBtn,SIGNAL(clicked()),this,SLOT(StartBtnClicked()));

    // 定时器触发，循环发送数据
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
}

UdpServer::~UdpServer()
{
    
}

void UdpServer::StartBtnClicked()
{
    // 开始广播，并调整按钮显示字样
    if(!isStarted)
    {
        StartBtn->setText(tr("停止广播"));
        timer->start(1000);
        isStarted =true;
    }

    // 停止广播，并调整按钮显示字样
    else
    {
        StartBtn->setText(tr("开始广播"));
        isStarted = false;
        timer->stop();
    }
}

void UdpServer::timeout()
{
    QString msg = TextLineEdit->text();
    if(msg.isEmpty())
       return;

    // 将编辑栏中的数据, 广播发送出去
    udpSocket->writeDatagram(msg.toLatin1(),
                             msg.length(),
                             QHostAddress::Broadcast,
                             port);
}
