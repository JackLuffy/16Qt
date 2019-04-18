#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QToolButton>
#include <QPlainTextEdit>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QLabel>
#include <QFontComboBox> // 字体下拉框
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    const float defaultFontSize = 12;

private:
    Ui::MainWindow *ui;

    QMenu *fileMenu;
    QAction *openFileAct;
    QAction *saveFileAct;
    QAction *quitAct;

    QMenu *editMenu;
    QAction *copyAct;
    QAction *cutAct;
    QAction *pasteAct;

    // 从Action中来
    QToolBar *fileToolBar; // 打开、保存、退出
    QToolBar *editToolBar; // 复制、剪切、粘贴
    // 单独定义
    QToolButton *boldBtn;  // 粗体
    QToolButton *italicBtn; // 斜体
    QToolButton *paletteBtn; // 颜色
    // 字体
    QLabel *fontLabel;
    QFontComboBox *fontComboBox;
    // 字号
    QLabel *fontSizeLabel;
    QComboBox *fontSizeComboBox;


    QPlainTextEdit *pTextEdit;

    QTextCursor tc;

    void createActions();
    void createMenus();
    void createToolBars();

private slots:
    void openFile();
    void saveFile();

    void setBold(bool checked);
    void setItalic(bool checked);
    void setPalette();
    void setFont();

    void showCurrentFmtChange();
    void showCurrentFont();
};

#endif // MAINWINDOW_H
