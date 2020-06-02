#ifndef APP_H
#define APP_H
#include <QObject>
#include <QSet>
#include <QTcpServer>
#include "user.h"
#include "sslserver.h"
class app : public QObject
{
    Q_OBJECT
public:
    app();
private :
    QSet<user> m_users;
    sslServer *m_server;
    quint64 nextId=0; //For QSet hash-based array.
public slots :
    void newUser(QSslSocket * socket);
};
#endif // APP_H
