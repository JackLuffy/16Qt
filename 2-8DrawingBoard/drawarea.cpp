#include "drawarea.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>

drawArea::drawArea(QWidget *parent) : QWidget(parent)
{
    pix = new QPixmap(this->size());
    pix->fill(Qt::white);

    // 初始化默认笔触
    color = Qt::black;
    width = 2;
    style = Qt::SolidLine;
}

void drawArea::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(QPoint(0,0), *pix);
}

void drawArea::mousePressEvent(QMouseEvent *e)
{
    beginPoint = e->pos();
}

void drawArea::mouseMoveEvent(QMouseEvent *e)
{
    QPainter *p = new QPainter;

    QPen pen;
    pen.setCapStyle(Qt::RoundCap);
    pen.setColor(color);
    pen.setWidth(width);
    pen.setStyle(Qt::PenStyle(style));

    p->begin(pix);
    p->setRenderHint(QPainter::Antialiasing); // 抗锯齿
    p->setPen(pen);
    p->drawLine(beginPoint, e->pos());
    p->end();
    beginPoint = e->pos();

    update();
}

void drawArea::resizeEvent(QResizeEvent *e)
{
    if(this->height() <= pix->height() && this->QWidget::width() <= pix->width())
        return;

    QPixmap *newPix = new QPixmap(this->size());
    newPix->fill(Qt::white);

    QPainter p;
    p.begin(newPix);
    p.drawPixmap(QPoint(0,0), *pix);
    p.end();

    delete pix;
    pix = newPix;
}

void drawArea::setPenStyle(int s)
{
    style = s;
}

void drawArea::setPenWidth(int w)
{
    width = w;
}

void drawArea::setPenColor(QColor c)
{
    color = c;
}

void drawArea::clear()
{
    pix->fill(Qt::white);
    update();
}
