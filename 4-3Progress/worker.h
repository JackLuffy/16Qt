#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QProgressBar>

class Worker : public QThread
{
public:
    Worker(QProgressBar *p, int begin=0, int max = 100);

    void run();

private:
    QProgressBar *bar;
    int beginValue;
    int maxValue;
};

#endif // WORKER_H
