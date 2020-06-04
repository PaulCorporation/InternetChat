#ifndef APP_H
#define APP_H
#include <QObject>
#include <QSet>
#include <QTcpServer>
#include "user.h"
#include "sslserver.h"
#include "database.h"
/*app manage all clients, it is also the vertebral column of the program.
app class contains all clients, and also manage clients deletion.
For best performances, clients are stoked in a hash-based container.*/
class app : public QObject
{
    Q_OBJECT
public:
    app();
private :
    QSet<user*> m_users;
    sslServer *m_server;
    database m_db;
public slots :
    void flush(user*); //flush(user*) erase disconnected clients.
    void broadcast(message);
    void incomingConnection();
};

#endif // APP_H
