#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QFileDialog>
#include <QByteArray>
#include <QMessageBox>
#include <QColorDialog>
#include <QColor>
#include <QFontDatabase> // 字库

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 去掉原始的默认工具栏
//    QList<QToolBar *>toolBars = findChildren<QToolBar *>();
//    foreach(QToolBar *tb, toolBars)
//    {
//        removeToolBar(tb);
//    }
    this->removeToolBar(ui->mainToolBar);

    // 创建中央编辑区
    pTextEdit = new QPlainTextEdit;
    this->setCentralWidget(pTextEdit);

    // 创建一些控件
    boldBtn = new QToolButton(this);
    italicBtn = new QToolButton(this);
    paletteBtn = new QToolButton(this);

    boldBtn->setIcon(QIcon("bold.png"));
    italicBtn ->setIcon(QIcon("italic.png"));
    paletteBtn->setIcon(QIcon("palette.png"));

    boldBtn->setCheckable(true);
    italicBtn ->setCheckable(true);
    paletteBtn->setCheckable(false);

    fontLabel = new QLabel("字体", this);
    fontComboBox = new QFontComboBox(this);

    fontSizeLabel = new QLabel("字号", this);
    fontSizeComboBox = new QComboBox(this);
    QFontDatabase fontDB;
    foreach (int size, fontDB.standardSizes())
    {
        fontSizeComboBox->addItem(QString::number(size));
    }
    fontSizeComboBox->setCurrentIndex(fontSizeComboBox->findText(QString::number(defaultFontSize)));

    // 创建动作
    createActions();
    createMenus();
    createToolBars();

    // 关联动作的信号与槽
    connect(this->openFileAct, SIGNAL(triggered(bool)), this, SLOT(openFile()));
    connect(this->saveFileAct, SIGNAL(triggered(bool)), this, SLOT(saveFile()));
    connect(this->quitAct, SIGNAL(triggered(bool)), this, SLOT(close()));

    connect(this->copyAct, SIGNAL(triggered(bool)), pTextEdit, SLOT(copy()));
    connect(this->cutAct, SIGNAL(triggered(bool)), pTextEdit, SLOT(cut()));
    connect(this->pasteAct, SIGNAL(triggered(bool)), pTextEdit, SLOT(paste()));

    // 点击工具栏按钮时，改变选中的文本的外观格式
    connect(this->boldBtn, SIGNAL(clicked(bool)), this, SLOT(setBold(bool)));
    connect(this->italicBtn, SIGNAL(clicked(bool)), this, SLOT(setItalic(bool)));
    connect(this->paletteBtn, SIGNAL(clicked(bool)), this, SLOT(setPalette()));

    // 改变当前选中的文本时，修改相应的工具栏状态
    connect(pTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(showCurrentFmtChange()));

    // 修改字体和字号
    connect(this->fontComboBox, SIGNAL(currentFontChanged(QFont)),
            this, SLOT(setFont()));
    connect(this->fontSizeComboBox, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(setFont()));

    // 改变当前选中的文本时，修改相应的工具栏状态
    connect(pTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(showCurrentFont()));

    resize(800, 500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    openFileAct = new QAction(QIcon("open.png"), "打开", this);
    saveFileAct = new QAction(QIcon("save.png"), "保存", this);
    quitAct     = new QAction(QIcon("quit.png"), "退出", this);

    copyAct  = new QAction(QIcon("copy.png"), "复制", this);
    cutAct   = new QAction(QIcon("cut.png"), "剪切", this);
    pasteAct = new QAction(QIcon("paste.png"), "粘贴", this);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu("文件");
    fileMenu->addAction(openFileAct);
    fileMenu->addAction(saveFileAct);
    fileMenu->addAction(quitAct);

    editMenu = menuBar()->addMenu("编辑");
    editMenu ->addAction(copyAct);
    editMenu ->addAction(cutAct);
    editMenu ->addAction(pasteAct);
}

void MainWindow::createToolBars()
{
    fileToolBar = this->addToolBar("文件");
    fileToolBar->addAction(openFileAct);
    fileToolBar->addAction(saveFileAct);
    fileToolBar->addAction(quitAct);
    fileToolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::TopToolBarArea);

    editToolBar = this->addToolBar("编辑");
    editToolBar->addAction(copyAct);
    editToolBar->addAction(cutAct);
    editToolBar->addAction(pasteAct);
    editToolBar->addSeparator();

    editToolBar->addWidget(boldBtn);
    editToolBar->addWidget(italicBtn);
    editToolBar->addWidget(paletteBtn);

    editToolBar->addSeparator();
    editToolBar->addWidget(fontLabel);
    editToolBar->addWidget(fontComboBox);
    editToolBar->addWidget(fontSizeLabel);
    editToolBar->addWidget(fontSizeComboBox);

    editToolBar->setAllowedAreas(Qt::RightToolBarArea | Qt::TopToolBarArea);
}

void MainWindow::openFile()
{
    static QString dir = "/";
    QString filter;
    filter += "所有文件(*)";

    QString name = QFileDialog::getOpenFileName(NULL, "打开文件", dir, filter);
    if(name.isNull())
        return;

    QFile file(name);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::information(this, "打开文件错误", file.errorString());
        return;
    }

    QByteArray ba;
    while(!file.atEnd())
    {
        ba = file.readAll();
        pTextEdit->clear();
        pTextEdit->appendPlainText(QString(ba));
    }

    pTextEdit->selectAll();
    QTextCharFormat fmt;
    fmt.setFontPointSize(defaultFontSize);
    pTextEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::saveFile()
{
    qDebug() << "保存文件。。。";
}

// 设置粗体
void MainWindow::setBold(bool checked)
{
    QTextCharFormat fmt;
    fmt.setFontWeight(checked ? QFont::Bold : QFont::Normal);
    pTextEdit->mergeCurrentCharFormat(fmt);
}

// 设置斜体
void MainWindow::setItalic(bool checked)
{
    QTextCharFormat fmt;
    fmt.setFontItalic(checked);
    pTextEdit->mergeCurrentCharFormat(fmt);
}

// 设置颜色
void MainWindow::setPalette()
{
    QColor c = QColorDialog::getColor();
    if(!c.isValid())
        return;

    QTextCharFormat fmt;
    fmt.setForeground(c);
    pTextEdit->mergeCurrentCharFormat(fmt);
}

// 设置字体、字号
void MainWindow::setFont()
{
    QFont font = fontComboBox->currentFont();
    int   size = fontSizeComboBox->currentText().toInt();

    QTextCharFormat fmt;
    fmt.setFont(font);
    fmt.setFontPointSize(size);
    pTextEdit->mergeCurrentCharFormat(fmt);
}

// 将选中的文本的粗体和斜体状态反映到工具栏的按钮上
void MainWindow::showCurrentFmtChange()
{
    QTextCharFormat fmt;
    fmt = pTextEdit->currentCharFormat();

    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.font().italic());
}

// 将选中的文本的字体和字号状态反映到工具栏的按钮上
void MainWindow::showCurrentFont()
{
    QTextCharFormat fmt;
    fmt = pTextEdit->currentCharFormat();

    // 设置当前字体
    fontComboBox->setCurrentFont(fmt.font());

    // 设置当前字号
    int curSize = fmt.fontPointSize();
    if(curSize <= 0)
        return;

    int index = fontSizeComboBox->findText(QString::number(curSize));
    fontSizeComboBox->setCurrentIndex(index);
}
