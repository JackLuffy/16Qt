#ifndef MYSQLMODEL_H
#define MYSQLMODEL_H

#include <QSqlQueryModel>
#include <QWidget>

class mySqlModel : public QSqlQueryModel
{
public:
    mySqlModel(QWidget *parent=0);

    // 复写item权限管理虚函数
    Qt::ItemFlags flags(const QModelIndex &index) const;

    // 复写item呈现虚函数
    QVariant data(const QModelIndex &item, int role) const;

    // 复写改写item的虚函数
    bool setData(const QModelIndex &index, const QVariant &value, int role);

private:
    bool modify_type(int id, QString newT);
    bool modify_price(int id, float newP);

    void refetch();
};

#endif // MYSQLMODEL_H
