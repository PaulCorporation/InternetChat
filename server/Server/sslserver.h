#ifndef SSLSERVER_H
#define SSLSERVER_H
#include <QTcpServer>
#include <QSslSocket>
/*sslServer class intialize ssl communication by using the reimplemented
 method incomingConnection, the sslServer class work as a standard TcpServer class with
the pending connections system.*/
class sslServer : public QTcpServer
{
  Q_OBJECT
public:
    sslServer(QObject *parent = nullptr);
    void incomingConnection(qintptr socketDescriptor) override;
public slots :
    void sslErrors(const QList<QSslError> &errors);
};

#endif // SSLSERVER_H
