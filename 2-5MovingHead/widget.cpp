#include "widget.h"
#include <QColor>
#include <QPalette>
#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setAutoFillBackground(true);

    // 设置背景、大小和初始位置
    QPalette p;
    p.setColor(QPalette::Background, Qt::white);
    this->setPalette(p);

    // 调整窗体尺寸
    this->resize(600, 400);

    QDesktopWidget *desktop = QApplication::desktop();
    int x = (desktop->geometry().width() - this->width() ) /2;
    int y = (desktop->geometry().height()- this->height()) /2;

    // 将窗体移到屏幕中央
    this->move(x, y);

    // 设置头像起始位置
    point.setX(0);
    point.setY(0);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *e)
{
    qDebug() << "paintEvent";

    // 画网格和头像
    drawGrid();
    drawHead();
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    int x = this->point.x();
    int y = this->point.y();

    // 判断是否按住ctrl键进行微调
    int step = (e->modifiers() == Qt::ControlModifier) ? 1 : 15;

    switch(e->key())
    {
    case Qt::Key_Left:
        this->point.setX(x-step);
        break;
    case Qt::Key_Right:
        this->point.setX(x+step);
        break;
    case Qt::Key_Down:
        this->point.setY(y+step);
        break;
    case Qt::Key_Up:
        this->point.setY(y-step);
        break;
    }

    update();
}

void Widget::drawGrid()
{
    QPainter *p = new QPainter(this);

    // 准备画笔
    QPen pen;
    pen.setWidth(1);
    pen.setStyle(Qt::DashLine);
    pen.setColor(Qt::lightGray);
    p->setPen(pen);

    // 画横线
    for(int i=15; i<this->height(); i+=15)
        p->drawLine(QPoint(0, i), QPoint(this->width(), i));

    // 画竖线
    for(int i=15; i<this->width(); i+=15)
        p->drawLine(QPoint(i, 0), QPoint(i, this->height()));

    delete p;
}

void Widget::drawHead()
{
    QPixmap pix(":/head/portrait3.png");

    if(pix.isNull())
        return;

    QPainter p(this);
    p.drawPixmap(point, pix.scaled(80, 80, Qt::KeepAspectRatio));
}
