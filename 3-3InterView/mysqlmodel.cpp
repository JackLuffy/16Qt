#include "mysqlmodel.h"
#include <QByteArray>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

mySqlModel::mySqlModel(QWidget *parent)
    :QSqlQueryModel(parent)
{

}

Qt::ItemFlags mySqlModel::flags(const QModelIndex &index) const
{
    // 获取父类的对此item的默认权限
    Qt::ItemFlags flgs = QSqlQueryModel::flags(index);

    // 除了序号和库存，其他允许编辑
    if(index.column() != 0 && index.column() != 4)
        flgs |= Qt::ItemIsEditable;

    return flgs;
}

QVariant mySqlModel::data(const QModelIndex &item, int role) const
{
    QVariant data = QSqlQueryModel::data(item, role);

    // 序号居中
    if(item.column() == 0 && role == Qt::TextAlignmentRole)
        return Qt::AlignCenter;

    // 价格蓝色显示，并加上人民币符￥
    if(item.column() == 3 && role == Qt::TextColorRole)
        return QColor(Qt::blue);
    if(item.column() == 3 && role == Qt::DisplayRole)
        return QString("￥%1").arg(data.toString());

    return data;
}

bool mySqlModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    QModelIndex IDindex = QSqlQueryModel::index(index.row(), 0);
    int id = QSqlQueryModel::data(IDindex).toInt();

    bool ok;
    switch (index.column())
    {
    case 1: // 修改类别
        ok = modify_type(id, value.toString());
        break;
    case 3: // 修改价格
        ok = modify_price(id, value.toFloat());
        break;
    default:
        break;
    }

    // 重新抓取数据库的数据
    refetch();

    return ok;
}

bool mySqlModel::modify_type(int id, QString newT)
{
    QString SQL = "UPDATE guns SET type=? WHERE id=?";

    QSqlQuery query;
    query.prepare(SQL);
    query.addBindValue(newT);
    query.addBindValue(id);

    bool ok = query.exec();

    if(!ok)
    {
        qDebug() << query.lastError().databaseText();
    }

    return ok;
}

bool mySqlModel::modify_price(int id, float newP)
{
    QString SQL = "UPDATE guns SET price=? WHERE id=?";

    QSqlQuery query;
    query.prepare(SQL);
    query.addBindValue(newP);
    query.addBindValue(id);

    bool ok = query.exec();

    if(!ok)
    {
        qDebug() << query.lastError().databaseText();
    }

    return ok;

}

void mySqlModel::refetch()
{
    this->setQuery("SELECT * FROM guns");
}
