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
    QObject::connect(m_server, &QTcpServer::newConnection, this, &app::incomingConnection);

}
void app::incomingConnection()
{
    QTcpSocket *soc  = m_server->nextPendingConnection();

    if(dynamic_cast<QSslSocket*>(soc))
    {QSslSocket *socket =dynamic_cast<QSslSocket*>(soc);
        qDebug() << "Nouvelle connexion.";
        m_users.insert(new user(socket, nextId, &m_db));
        bool done = false;
        for(auto it = m_users.begin(); it != m_users.end() && !done; ++it)
        {
            if((*it)->getId() == nextId)
            {
              QObject::connect((*it), &user::requestToKill, this, &app::flush, Qt::DirectConnection);
              QObject::connect((*it), &user::requestBroadcast, this, &app::broadcast);
            }
        }
        ++nextId;
    }
}

void app::flush(quint64 id)
{
    qDebug() << QString("Deconnexion de l'utilisateur %1").arg(QString::number(id));
    bool destroyed = false;
    user *to_delete =nullptr;
    for(auto it = m_users.begin();!destroyed; ++it)
    {
        if((*it)->getId() == id)
        {
               qDebug() << QString("Déconnexion de %1").arg(QString::number(id));
               qDebug() << QString("%1 clients restants.").arg(QString::number(m_users.count()-1));
               destroyed = true;
               user* to_delete = *it;


        }
    }
    m_users.remove(to_delete);
    delete(to_delete);
    qDebug()  << "Deconnexion effectuée.";
}
void app::broadcast(message msg)
{
    for(auto it = m_users.begin(); it != m_users.end(); ++it)
    {

        (*it)->sendMsg(msg);
    }

}
