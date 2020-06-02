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
    m_users.insert(user(socket, nextId));
    ++nextId;
}
