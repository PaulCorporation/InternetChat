#include "user.h"
#include <QDebug>
user ::user (QSslSocket *socket, database *db)
{
    m_socket = socket;
    QObject::connect(socket, &QSslSocket::disconnected, this,&user::kill, Qt::DirectConnection);
    connect( m_socket, qOverload<QAbstractSocket::SocketError>(&QAbstractSocket::error), this, &user::computeError);
    connect(socket, &QSslSocket::encrypted, this, &user::allow);
    m_db = db;
    in.setDevice(m_socket);
}
user::user (const user& usr)
{
    m_socket = usr.m_socket;
    m_nickname = usr.m_nickname;
    m_login = usr.m_login;
}
QSslSocket* user::getSocket() const
{
    return m_socket;
}
void user::kill()
{

    qDebug() << "Appel à requestToKill()";
    emit requestToKill(this); // requestToKill signal ask app to erase current user.
}
void user::computeError(QAbstractSocket::SocketError error)
{
    qDebug() << m_socket->errorString();
}
void user::computePendingDatagram()
{
    if(m_socket)
    {


    qDebug() << "Paquet recu";
    in.startTransaction();
    quint8 header = 0;
    in >> header;
    packet * request = nullptr;
    switch(header)
        {
            case 0:
                {
                request = new loginRequest;
                *request << in;}
            break;
            case 1 :
                {
                request = new signupRequest;
                *request << in;
                 qDebug() << "Requête d'incription reçue.";
                }
            break;
            case 2 :
                {
                 request = new message;
                *request << in;}
            break;

        }
    if(in.commitTransaction())
    {
        switch(header)
            {

                case 0:
                    {
                     loginRequest *packet = static_cast<loginRequest*>(request);
                     bool success = m_db->authenticate(packet->getPassword(),packet->getMail(), m_nickname);
                     if(success)
                     {
                        m_login=true;
                        qDebug() << QString("L'utilisateur %1 s'est bien connecté.").arg(m_nickname);
                        /*TODO
                        We have to say to the user that his account was successfuly loged.
                        by using '3' unsigned 8-bit flag;
                        */
                            {
                            QByteArray data;
                            QDataStream out(&data, QIODevice::WriteOnly);
                            quint8 flag (3);
                            out << flag;
                            send(data);
                            }
                     }
                    }
                break;
                case 1:
                    {signupRequest *packet = static_cast<signupRequest*>(request);
                    qDebug() << QString("User : %1").arg(packet->getUser());
                    qDebug() << QString("Mail : %1").arg(packet->getMail());
                    bool success = m_db->signup(packet->getUser(),packet->getMail(), packet->getPassword());
                    if(success)
                        {
                        m_login = true;
                        qDebug() << QString("L'utilisateur %1 a été ajouté à la base").arg(packet->getUser());
                        /*TODO
                        We have to say to the user that his account was successfuly created.
                        by using '4' unsigned 8-bit flag;
                        */
                            {
                            QByteArray data;
                            QDataStream out(&data, QIODevice::WriteOnly);
                            quint8 flag (4);
                            out << flag;
                            send(data);
                            }
                        }
                    }
                break;
                case 2:
                     {
                        if(m_login)
                        {
                            message *packet = static_cast<message*>(request);
                            packet->setUser(m_nickname); // Avoid autoset username glitch.
                            emit requestBroadcast(*packet);
                        }
                     }
                break;
            }

    }
    else {
       qDebug() << "Erreur de lecture.";
    }
    delete request;

    }
}
void user::sendMsg(message msg) const
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    msg >> out;
    send(data);

}
void user::send(QByteArray &data) const
{
    if(m_socket)
    if(m_socket->write(data) == -1)
        qDebug()<< "Un problème est survenu pendant l'envoi d'un paquet";
}
void user::allow()
{
    connect(m_socket, &QAbstractSocket::readyRead, this,  &user::computePendingDatagram);
}
