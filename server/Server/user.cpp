#include "user.h"
#include <QDebug>
user ::user (QSslSocket *socket, database *db)
{
    m_socket = socket;
    QObject::connect(socket, &QSslSocket::disconnected, this,&user::kill, Qt::DirectConnection);
    QObject::connect(socket, &QSslSocket::disconnected, this,&user::refreshList);
    connect( m_socket, qOverload<QAbstractSocket::SocketError>(&QAbstractSocket::error), this, &user::computeError);
    if(m_socket->isEncrypted())
        user::allow();
    connect(m_socket, &QSslSocket::encrypted, this, &user::allow);
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
    while(m_socket->bytesAvailable()>0)
    {
    if(m_socket)
    {


    qDebug() << "Paquet recu";
    in.startTransaction();
    quint8 header8bit = 0;
    in >> header8bit;
    packet_type header = static_cast<packet_type>(header8bit);
    packet * request = nullptr;
    switch(header)
        {
            case packet_type::LOGIN_REQUEST:
                {
                qDebug() << "Requête de login reçue.";
                request = new loginRequest;
                *request << in;}
            break;
            case ::packet_type::SIGNUP_REQUEST :
                {
                request = new signupRequest;
                *request << in;
                 qDebug() << "Requête d'incription reçue.";
                }
            break;
            case packet_type::MESSAGE :
                {
                  qDebug() << "Message recu";
                 request = new message;
                *request << in;}
            break;

        }
    if(in.commitTransaction())
    {
        switch(header)
            {

                case packet_type::LOGIN_REQUEST:
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
                            quint8 flag =static_cast<quint8>(packet_type::LOGIN_SUCCESFULL);
                            out << flag;
                            send(data);
                            emit refreshList();
                            }
                     }
                     else {

                         {
                         QByteArray data;
                         QDataStream out(&data, QIODevice::WriteOnly);
                         quint8 flag =static_cast<quint8>(packet_type::LOGIN_FAILED);
                         out << flag;
                         send(data);
                         }
                         qDebug() << "Echec de l'authentification";
                     }
                    }
                break;
                case packet_type::SIGNUP_REQUEST:
                    {signupRequest *packet = static_cast<signupRequest*>(request);
                    qDebug() << QString("User : %1").arg(packet->getUser());
                    qDebug() << QString("Mail : %1").arg(packet->getMail());
                    bool success = m_db->signup(packet->getUser(),packet->getMail(), packet->getPassword());
                    if(success)
                        {
                        m_login = true;
                        m_nickname = packet->getUser();
                        qDebug() << QString("L'utilisateur %1 a été ajouté à la base").arg(packet->getUser());
                        /*TODO
                        We have to say to the user that his account was successfuly created.
                        by using '4' unsigned 8-bit flag;
                        */
                            {
                            QByteArray data;
                            QDataStream out(&data, QIODevice::WriteOnly);
                            quint8 flag =static_cast<quint8>(packet_type::SIGNUP_SUCCESFULL);
                            out << flag;
                            send(data);
                            }
                            emit refreshList();
                        }
                    else {
                        {
                        QByteArray data;
                        QDataStream out(&data, QIODevice::WriteOnly);
                        quint8 flag =static_cast<quint8>(packet_type::SIGNUP_FAILED);
                        out << flag;
                        send(data);
                        }
                    }
                    }
                break;
                case packet_type::MESSAGE:
                     {
                        if(m_login)
                        {
                            message *packet = static_cast<message*>(request);
                            packet->setUser(m_nickname); // Avoid autoset username glitch.
                            qDebug() << QString("Contenu : %1").arg(packet->getContent());
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
}
void user::sendMsg(message msg) const
{
    if(m_login && m_socket)
    {
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    msg >> out;
    send(data);
    }
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
void user::sendList(listMembers& list) const
{
    if(m_login && m_socket)
    {
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    list >> out;
    send(data);
    }
}
bool user::isLoged() const
    {
    return m_login;
}
 QString user::getNickname() const
 {
   return m_nickname;
 }
