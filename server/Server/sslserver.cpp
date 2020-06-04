#include "sslserver.h"
#include <QtGlobal>
#include <QDebug>
#include <QSslKey>
sslServer::sslServer(QObject *parent) : QTcpServer(parent)
{

}
void sslServer::incomingConnection(qintptr socketDescriptor)
{
        qDebug() << "connexion entrante";
        QSslSocket *serverSocket = new QSslSocket;
        if (serverSocket->setSocketDescriptor(socketDescriptor)) {

            QObject::connect(serverSocket, qOverload<const QList<QSslError> &>(&QSslSocket::sslErrors), this, &sslServer::sslErrors, Qt::DirectConnection);
            serverSocket->setLocalCertificateChain(QSslCertificate::fromPath("/etc/letsencrypt/live/paulcorporation.space/fullchain.pem", QSsl::Pem));
            qDebug() << "certificats trouvés : "<<  QString::number(serverSocket->localCertificateChain().size());
            serverSocket->setPrivateKey("/etc/letsencrypt/live/paulcorporation.space/privkey.pem", QSsl::Rsa, QSsl::Pem);
            qDebug() << serverSocket->localCertificate().version();
            qDebug() << serverSocket->localCertificate().publicKey();
            qDebug() << serverSocket->localCertificate().expiryDate();
            serverSocket->setProtocol(QSsl::TlsV1_2OrLater);
            serverSocket->startServerEncryption();
            addPendingConnection(serverSocket);
            QObject::connect(serverSocket, &QTcpSocket::disconnected, serverSocket,&QObject::deleteLater, Qt::DirectConnection);
            qDebug()<<"waiting for encrypted";
                    if(!serverSocket->waitForEncrypted(10000)){
                        qDebug()<<serverSocket->errorString();
                         qDebug()<<serverSocket->sslErrors();
                        return;
                    }
                    qDebug()<<"server encrypted";
        } else {
            delete serverSocket;
        }
}

void sslServer::sslErrors(const QList<QSslError> &errors)
{
    for(auto it = errors.begin(); it != errors.end(); ++it)
    {
        qDebug() << it->errorString();
    }
}
