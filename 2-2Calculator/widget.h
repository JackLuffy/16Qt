#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QKeyEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    enum optr{PLUS=10, MINUS, MULTI, DIVI, CE, DOT, EQ};

    void keyPressEvent(QKeyEvent *kpe);

private:
    Ui::Widget *ui;
    void setBtnMinimumSize(int w, int h);
    QButtonGroup *btnGroup;

private slots:
    void cal(int btnId);
};

#endif // WIDGET_H
