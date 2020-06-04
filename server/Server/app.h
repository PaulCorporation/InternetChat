#ifndef APP_H
#define APP_H
#include <QObject>
#include <QSet>
#include <QTcpServer>
#include "user.h"
#include "sslserver.h"
#include "database.h"
class app : public QObject
{
    Q_OBJECT
public:
    app();
private :
    QSet<user> m_users;
    sslServer *m_server;
    quint64 nextId=0; //For QSet hash-based array.
    database m_db;
public slots :
    void newUser(QSslSocket * socket);
    void flush(quint64); //flush(quint64) erase disconnected clients.
    void broadcast(message);
};

#endif // APP_H
