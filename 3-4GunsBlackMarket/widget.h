#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlQueryModel>
#include "editablesqlmodel.h"

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

    EditableSqlModel *model;

    // 下拉框数据来源
    QSqlQueryModel *ids;
    QSqlQueryModel *types;
    QSqlQueryModel *names;
    QSqlQueryModel *prices;
    QSqlQueryModel *remains;

private slots:
    void updatePanel(QString s);
    void updateAll();
};

#endif // WIDGET_H
