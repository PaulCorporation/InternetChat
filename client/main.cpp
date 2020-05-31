#include <QApplication>
#include "app.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    app application;
    return a.exec();
}
