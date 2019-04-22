#include "worker.h"

Worker::Worker(QProgressBar *p, int begin, int max)
    :bar(p), beginValue(begin), maxValue(max)
{

}

void Worker::run()
{
    int val = beginValue;

    while(val < maxValue)
    {
        val++;
        bar->setValue(val);
        usleep(50*1000);
    }
}
