#include <QCoreApplication>
#include "app.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    app run;
    return a.exec();
}
