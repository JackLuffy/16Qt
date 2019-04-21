#include <iostream>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QString>
#include <QStringList>

using namespace std;

void show(QSqlQuery query)
{
    QString SQL;
    SQL = "SELECT * FROM guns";
    if(!query.exec(SQL))
    {
        qDebug() << query.lastError().databaseText();
        return;
    }

    while(query.next())
    {
        int     id      = query.record().value(0).toInt();
        QString type    = query.record().value(1).toString().trimmed();
        QString version = query.record().value(2).toString().trimmed();
        QString coutry  = query.record().value(3).toString().trimmed();

        qDebug() << qPrintable(QString("[%1] %2 %3 %4").arg(id).arg(coutry).arg(type).arg(version));
    }
}

QByteArray readImgData(const QString name)
{
    QFile file(name.trimmed());
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "读取图片文件失败";
        return QByteArray(0);
    }

    return file.readAll();
}

int main()
{
    // 增加本程序SQLite数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("a.db");

    // 打开并连接数据库
    if(!db.open())
    {
        qDebug() << "打开数据库失败";
        return 0;
    }

    QString SQL; // 存放标准SQL语句
    QSqlQuery query;

    // 试图删除原有的表
    SQL = "DROP TABLE IF EXISTS guns";
    if(!query.exec(SQL))
    {
        qDebug() << query.lastError().databaseText();
        return 0;
    }

    // 构建一张表: guns
    SQL = "CREATE TABLE IF NOT EXISTS guns(序号 INT PRIMARY KEY,"
          "								   类别 TEXT,"
          "								   型号 TEXT,"
          "								   产地 TEXT,"
          "								   图片 BLOB)";
    if(!query.exec(SQL))
    {
        qDebug() << query.lastError().databaseText();
        return 0;
    }

    // 插入一些数据
//    SQL = "INSERT INTO guns(序号,类别,型号,产地) VALUES(1, '自动步枪', '赫克勒-科赫HK 416', '德国')";
//    if(!query.exec(SQL))
//    {
//        qDebug() << query.lastError().databaseText();
//        return 0;
//    }
//    SQL = "INSERT INTO guns(序号,类别,型号,产地) VALUES(2, '自动步枪', 'M4卡宾枪', '美国')";
//    if(!query.exec(SQL))
//    {
//        qDebug() << query.lastError().databaseText();
//        return 0;
//    }

    QFile file("guns.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << __LINE__ << file.errorString();
        return 0;
    }

    QByteArray ba;
    QString line;
    SQL = "INSERT INTO guns VALUES(?,?,?,?,?)";
    query.prepare(SQL);
    for(int i=1; ;i++)
    {
        if((ba=file.readLine()).isEmpty())
            break;

        if((line=QString(ba)).trimmed().isEmpty())
            continue;

        QStringList tmp = line.split(QChar(','));

        query.bindValue(0, i); // 序号
        query.bindValue(1, tmp[0]); // 类别
        query.bindValue(2, tmp[1]); // 型号
        query.bindValue(3, tmp[2]); // 产地
        query.bindValue(4, readImgData(tmp[3])); // 图片

        if(!query.exec())
        {
            qDebug() << query.lastError().databaseText();
            break;
        }
    }

    // 查看数据
    show(query);

    // 删除美国的条目
    SQL = "DELETE FROM guns WHERE 产地 LIKE '%美国%'";
    if(!query.exec(SQL))
    {
        qDebug() << query.lastError().databaseText();
        return 0;
    }
    qDebug() << endl << "删除之后:";
    show(query);

    return 0;
}
