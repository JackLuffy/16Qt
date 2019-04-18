#include "digitalclock.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DigitalClock c;
    c.show();

    return a.exec();
}
