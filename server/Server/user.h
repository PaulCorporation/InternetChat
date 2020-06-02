#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QObject>
#include <QSslSocket>
#include <QHash>
class user : public QObject
{
Q_OBJECT
public:
    user (QSslSocket *socket, quint64 id);
    user (const user& usr);
    ~user ();
    QSslSocket* getSocket() const;
    quint64 getId() const;
    bool operator==(const user& other) const;
private:
    QSslSocket *m_socket;
    quint64 m_id = 0;
};
inline uint qHash(const user&usr) {
    return qHash(usr.getId());
}
#endif // UTILISATEUR_H
