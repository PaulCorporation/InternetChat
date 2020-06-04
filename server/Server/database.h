#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
/*The database class manage all communications with the Mysql database.
database's methods are called from user instances to request some database related features.*/
class database
{
public:
    database();
    bool authenticate(QString password, QString mail, QString &name);
    bool signup(QString user, QString mail, QString password);
    QSqlDatabase db;
};

#endif // DATABASE_H
