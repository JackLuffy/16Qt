#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QString>

using namespace std;

int main(int argc, char **argv)
{
    QFile ifile(argv[1]);
    QFile ofile(argv[2]);

    ifile.open(QIODevice::ReadOnly);
    ofile.open(QIODevice::WriteOnly | QIODevice::Truncate);

    QByteArray ba;
    while(!ifile.atEnd())
    {
        ba = ifile.readAll();
        ofile.write(ba);
    }

    ifile.close();
    ofile.close();


    return 0;
}
