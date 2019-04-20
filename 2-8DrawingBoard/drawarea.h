#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>
#include <QPixmap>
#include <QColor>

class drawArea : public QWidget
{
    Q_OBJECT

public:
    explicit drawArea(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

signals:

public slots:
    void setPenStyle(int s);
    void setPenWidth(int w);
    void setPenColor(QColor c);
    void clear();

private:
    QPoint beginPoint;
    QPoint endPoint;

    QPixmap *pix;

    int style;
    int width;
    QColor color;
};

#endif // DRAWAREA_H
