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
        user *usr = new user(socket,&m_db);
        QObject::connect(usr, &user::requestToKill, this, &app::flush, Qt::DirectConnection);
        QObject::connect(usr, &user::requestBroadcast, this, &app::broadcast);
        QObject::connect(usr, &user::refreshList, this, &app::broadCastListNames);
        m_users.insert(usr);
    }
}

void app::flush(user* usr)
{
    m_users.remove(usr);
    delete(usr);
    qDebug()  << "Deconnexion effectuée.";
}
void app::broadcast(message msg)
{
    qDebug() << "Broadcasting";
    for(auto it = m_users.begin(); it != m_users.end(); ++it)
    {

        (*it)->sendMsg(msg);
    }

}
void app::broadCastListNames()
{
    listMembers list;
    for(auto it = m_users.begin(); it !=m_users.end(); ++it)
    {
    if((*it)->isLoged())
    list.addMember((*it)->getNickname());
    }
    for(auto it = m_users.begin(); it !=m_users.end(); ++it)
    {
     if((*it)->isLoged())
     {
        (*it)->sendList(list);
     }
    }
}
