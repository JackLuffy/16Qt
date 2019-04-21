#ifndef EDITABLESQLMODEL_H
#define EDITABLESQLMODEL_H

#include <QSqlQueryModel>
#include <QModelIndex>
#include <QWidget>

class EditableSqlModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    EditableSqlModel(QWidget *parent=0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant data(const QModelIndex &item, int role) const;

private:
    bool modify_type(int id, QString newType);
    bool modify_name(int id, QString newName);
    void refetchDB();
};

#endif // EDITABLESQLMODEL_H
