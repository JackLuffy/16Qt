#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QStringList>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Widget *ui;

    QList<QStringList> city;
};

#endif // WIDGET_H
