#include "apgmain.h"
#include <QApplication>
#include "cstdlib"
#include "errornoapg.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    APGMain w;
    w.show();

    return a.exec();
}
