#include "editablesqlmodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

EditableSqlModel::EditableSqlModel(QWidget *parent)
    :QSqlQueryModel(parent)
{
    refetchDB();
}

// 设置每一个项的权限和属性
Qt::ItemFlags EditableSqlModel::flags(const QModelIndex &index) const
{
    // 调用父类的flags版本，获取原先的权限
    Qt::ItemFlags f = QSqlQueryModel::flags(index);

    if(index.column() != 0)
        f |= Qt::ItemIsEditable;

    return f;
}

bool EditableSqlModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    // 序号与库存不可编辑
    if(index.column() == 0/*序号*/ || index.column() == 4/*库存*/)
        return false;

    // 取得当前行的id
    QModelIndex IDindex = QSqlQueryModel::index(index.row(), 0);
    int id = QSqlQueryModel::data(IDindex).toInt();

    // 根据当前修改的位置，调用不同函数
    bool ok;
    switch(index.column())
    {
    case 1: ok = modify_type(id, value.toString());
            qDebug() << __LINE__;
            break;
    case 2: ok = modify_name(id, value.toString());
            qDebug() << __LINE__;
            break;
    }

    // 重新将数据库模的数据加载到型中
    refetchDB();

    return ok;
}

QVariant EditableSqlModel::data(const QModelIndex &item, int role) const
{
    // 调用父类中的data，获取原先的项
    QVariant value = QSqlQueryModel::data(item, role);

     // 1，所有的价格显示为蓝色
     if(item.column() == 3 && role == Qt::TextColorRole)
     {
         return QColor(Qt::blue);
     }

     // 2，所有的价格前面都加上人民币符号￥
     if(item.column() == 3 && role == Qt::DisplayRole)
         return QString("￥%1").arg(value.toFloat());


     // 3，所有项居中
     if(role == Qt::TextAlignmentRole)
         return Qt::AlignCenter;

     return value;
}

void EditableSqlModel::refetchDB()
{
    setQuery("SELECT * FROM guns");

    setHeaderData(0, Qt::Horizontal, "序号");
    setHeaderData(1, Qt::Horizontal, "类别");
    setHeaderData(2, Qt::Horizontal, "型号");
    setHeaderData(3, Qt::Horizontal, "价格");
    setHeaderData(4, Qt::Horizontal, "库存");
    setHeaderData(5, Qt::Horizontal, "备注");
}


bool EditableSqlModel::modify_type(int id, QString newType)
{
    qDebug() << __LINE__;
    QSqlQuery query;

    bool ok;
    query.prepare("UPDATE guns SET type = ? WHERE id = ?");
    query.addBindValue(newType);
    query.addBindValue(id);
    ok = query.exec();

    if(!ok)
    {
        qDebug() << query.lastError().databaseText();
    }

    return ok;
}

bool EditableSqlModel::modify_name(int id, QString newName)
{
    QSqlQuery query;

    bool ok;
    query.prepare("UPDATE guns SET name = ? WHERE id = ?");
    query.addBindValue(newName);
    query.addBindValue(id);

    ok = query.exec();
    if(!ok)
        qDebug() << query.lastError().databaseText();

    return ok;
}
