#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QTimer>
/*The database class manage all communications with the Mysql database.
database's methods are called from user instances to request some database related features.*/
class database : public QObject
{
    Q_OBJECT
public:
    database();

    bool authenticate(QString password, QString mail, QString &name);
    bool signup(QString user, QString mail, QString password);
    QSqlDatabase db;
private:
    QTimer m_timer;
public slots:
    bool connectDb();
};

#endif // DATABASE_H
