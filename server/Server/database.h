#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>

class database
{
public:
    database();
    bool authenticate(QString password, QString mail);
    bool signup(QString user, QString mail, QString password);
    QSqlDatabase db;
};

#endif // DATABASE_H
