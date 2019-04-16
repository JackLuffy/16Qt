#include "inputdiglog.h"
#include "ui_inputdiglog.h"

#include <QInputDialog>
#include <QStringList>

inputDiglog::inputDiglog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inputDiglog)
{
    ui->setupUi(this);
}

inputDiglog::~inputDiglog()
{
    delete ui;
}


void inputDiglog::on_pushButton_ChangeName_clicked()
{
    bool ok;
    QString newName = QInputDialog::getText(this, "标准字符串输入对话框",
                                            "请输入姓名", QLineEdit::Normal,
                                            ui->labelName->text(), &ok);
    if(ok && !newName.isEmpty())
            ui->labelName->setText(newName);
}

void inputDiglog::on_pushButton_ChangeSex_clicked()
{
    QStringList sex;
    sex.append(QString("男"));
    sex.append(QString("女"));
    sex.append(QString("保密"));
    QString newSex = QInputDialog::getItem(this, "标准条目选择对话框", "请选择性别",
                                        sex, sex.indexOf(ui->labelSex->text()), false);

    ui->labelSex->setText(newSex);

}

void inputDiglog::on_pushButton_ChangeAge_clicked()
{
    int age;
    age = QInputDialog::getInt(this, "标准整数对话框", "请选择年龄",
                            ui->labelAge->text().toInt(), 1, 100);

    ui->labelAge->setText(QString("%1").arg(age));
}

void inputDiglog::on_pushButton_ChangeScore_clicked()
{
    float score;
    score = QInputDialog::getDouble(this, "标准实数对话框", "请选择分数",
                            ui->labelScore->text().toDouble(), 0, 100);

    ui->labelScore->setText(QString("%1").arg(score));
}
