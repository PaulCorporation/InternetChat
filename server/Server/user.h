#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QObject>
#include <QSslSocket>
#include <QHash>
#include <QDataStream>
#include "database.h"
#include "packet.h"
/*The user class work with the app class together, this class manage user-related communications by using
ssl sockets.
user class algo contains user-related data, like nickname.*/
class user : public QObject
{
Q_OBJECT
public:
    user (QSslSocket *socket, database *db);
    user (const user& usr);
    QSslSocket* getSocket() const;
private:
    QSslSocket *m_socket;
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
    void requestToKill(user*);
    void requestBroadcast(message);
};
/*inline uint qHash(const user&usr) {
    return qHash(usr.getId());
}*/
#endif // UTILISATEUR_H
