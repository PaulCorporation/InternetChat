#include "app.h"
#include <QMessageLogger>
#include <QCoreApplication>
#define PORT 14256
app::app()
{
    m_server = new sslServer(this);
    if (!m_server->listen(QHostAddress::Any, PORT))
     {
        QMessageLogger(qPrintable("app.cpp"), 6, qPrintable("m_server->listen(listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0))")).debug() << "Impossible d'écouter sur le port " + QString::number(PORT);
        qApp->quit();
    }
    qDebug() << "Ecoute sur le port " + QString::number(PORT);
    QObject::connect(m_server, &sslServer::newPendingConnexion, this, &app::newUser);
}

void app::newUser(QSslSocket * socket)
{
    qDebug() << "Nouvelle connexion.";
    m_users.insert(user(socket, nextId, &m_db));
    ++nextId;
}
void app::flush(quint64 id)
{
    bool destroyed = false;
    for(auto it = m_users.begin(); it != m_users.end() && !destroyed; ++it)
    {
        if(it->getId() == id)
        {
               destroyed = true;
               m_users.erase(it);
        }
    }
}
void app::broadcast(message msg)
{
    for(auto it = m_users.begin(); it != m_users.end(); ++it)
    {

        it->sendMsg(msg);
    }

}
