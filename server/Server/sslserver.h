#ifndef SSLSERVER_H
#define SSLSERVER_H
#include <QTcpServer>
#include <QSslSocket>
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
