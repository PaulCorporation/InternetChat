#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QObject>
#include <QSslSocket>
#include <QHash>
#include <QDataStream>
#include "database.h"
#include "packet.h"
class user : public QObject
{
Q_OBJECT
public:
    user (QSslSocket *socket, quint64 id, database *db);
    user (const user& usr);
    QSslSocket* getSocket() const;
    quint64 getId() const;
    bool operator==(const user& other) const;
private:
    QSslSocket *m_socket;
    quint64 m_id = 0;
    database *m_db;
    QDataStream in;
    QString m_nickname;
    bool m_login = false;
    void send(QByteArray&) const;
public slots :
    void kill();
    void computeError(QAbstractSocket::SocketError error);
    void computePendingDatagram();
    void sendMsg(message) const;
    void allow();
signals :
    void requestToKill(quint64 id);
    void requestBroadcast(message);
};
/*inline uint qHash(const user&usr) {
    return qHash(usr.getId());
}*/
#endif // UTILISATEUR_H
