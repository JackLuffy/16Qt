#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QButtonGroup>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QGridLayout *mainLayout;

    void setBtnSize(int w, int h);
    void setBtnMinimumSize(int w, int h);

    QButtonGroup *btnGroup;

private slots:
    void cal(int btnId);
};

#endif // WIDGET_H
