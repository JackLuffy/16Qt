#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QMouseEvent>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mouseDoubleClickEvent(QMouseEvent *me);
    void mouseMoveEvent(QMouseEvent *me);
    void mousePressEvent(QMouseEvent *me);
    void mouseReleaseEvent(QMouseEvent *me);

private:
    QLabel *statusLabel;
    QLabel *mouseLabel;
    QLabel *a;
};

#endif // MAINWINDOW_H
