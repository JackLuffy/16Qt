#include "digitalclock.h"
#include <QTime>
#include <QDebug>

DigitalClock::DigitalClock(QWidget *parent)
    :QLCDNumber(parent)
{
    // 设置颜色
    p = new QPalette;
    p->setColor(QPalette::Background, Qt::lightGray);
    p->setColor(QPalette::Foreground, Qt::black);
    this->setPalette(*p);

    // 设置位置和大小
    this->move(300, 200);
    this->resize(200, 80);

    // 设置定时器，每隔一秒触发一次槽函数
    t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(showTime()));
    t->start(1000);

    // 一开始就让其显示时间，而不是等到1秒之后
    showTime();

    // 开启鼠标跟踪
    this->setMouseTracking(true);

    pressed = false;
}

void DigitalClock::mousePressEvent(QMouseEvent *me)
{
    if(me->button() == Qt::LeftButton)
    {
        pressed = true;
    }
}

void DigitalClock::mouseReleaseEvent(QMouseEvent *me)
{
    if(me->button() == Qt::LeftButton)
    {
        pressed = false;
    }
}

void DigitalClock::mouseMoveEvent(QMouseEvent *me)
{
    qDebug() << "全局坐标:" << me->globalPos();
    qDebug() << "鼠标位置:" << me->pos();
    qDebug() << "窗体位置:" << frameGeometry().topLeft() << "\n";

    if(!pressed)
        return;

    QPoint tmp = me->pos();
    this->move(me->globalPos() - tmp);
}

void DigitalClock::showTime()
{
    static bool colon = true;

    QTime now = QTime::currentTime();
    QString nowText = now.toString("hh:mm");

    if(colon)
    {
        nowText[2] = ':';
        colon = false;
    }
    else
    {
        nowText[2] = ' ';
        colon = true;
    }

    display(nowText);
}
