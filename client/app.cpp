#include "app.h"
#include <QSslKey>
#include "packet.h"
#include <QMessageBox>
app::app()
{
    m_socket = new QSslSocket(this);
    QObject::connect(m_socket, &QSslSocket::encrypted, this, &app::socketAvailable);
    QObject::connect(m_socket, qOverload<const QList<QSslError> &>(&QSslSocket::sslErrors), this, &app::sslErrors, Qt::DirectConnection);
    m_socket->setPeerVerifyName("paulcorporation.space");
    m_socket->connectToHostEncrypted("paulcorporation.space", 14256);
    QObject::connect(m_socket, &QSslSocket::encrypted, this, &app::allow);
    open_connexion_page();
    in.setDevice(m_socket);
}


app::~app()
{
    closeWindows();
    m_socket->close();
}

void app::allow()
{
     QObject::connect(m_socket, &QSslSocket::readyRead, this, &app::pendingData);
}

void app::open_account_creation_page() //Open account creation interface
{
    closeWindows();
    m_account_creation_page = new account_creation_page(nullptr);
    m_account_creation_page->show();
    QObject::connect(m_account_creation_page, &account_creation_page::requestConnexionPage, this, &app::open_connexion_page);
    QObject::connect( m_account_creation_page, &account_creation_page::requestSignup, this, &app::signup);
}


void app::open_connexion_page() // Open identification interface
{
    closeWindows();
    m_connexion_page = new connexion_page(nullptr);
    m_connexion_page->show();
    QObject::connect(m_connexion_page, &connexion_page::requestAccountCreationPage, this, &app::open_account_creation_page);
    QObject::connect(m_connexion_page, &connexion_page::requestLogin, this, &app::login);
    if(!m_socket->isEncrypted())
        m_connexion_page->updateStatus("Connexion en cours...");
    else {
        m_connexion_page->updateStatus("Connecté");
    }
}


void app::open_chat_page() // Open chatroom
{
    closeWindows();
    m_chat = new chat(nullptr);
    QObject::connect(m_chat, &chat::requestToSend, this, &app::requestSendData);
    QObject::connect(this, &app::newMessage, m_chat, &chat::newMessage);
    QObject::connect(this, &app::refreshList, m_chat, &chat::refreshList);
    m_chat->show();

}


void app::closeWindows() // Close all existing windows
{
    if(m_chat)
    {
        delete(m_chat);
        m_chat = nullptr;
    }
    if(m_account_creation_page)
    {
        delete(m_account_creation_page);
        m_account_creation_page=nullptr;
    }
    if(m_connexion_page)
    {
        delete(m_connexion_page);
        m_connexion_page = nullptr;
    }
}


void app::socketAvailable() // Send "connected" string to the identification page.
{

    if(m_connexion_page)
    {
        m_connexion_page->updateStatus("Connecté");
    }
}
void app::sslErrors(const QList<QSslError> &errors)
{
    for(auto it = errors.begin(); it != errors.end(); ++it)
    {
        qDebug() << it->errorString();
    }
}
void app::login(QString addr, QString pass) // Send a login request to the remote server.
{
    if(m_socket->isEncrypted())
    {
        if(m_connexion_page)
            m_connexion_page->updateStatus("Authentification en cours...");
            loginRequest packet;
            packet.setMail(addr);
            packet.setPassword(pass);
            QByteArray data;
            QDataStream out(&data, QIODevice::WriteOnly);
            packet >> out;
            m_socket->write(data);
        /*Structure of a login-request packet :
        8bit unsigned : header (0)
        QString : Addr
        QString : pass
        All data should be serialized by using QDataSream to avoid endianess problems.
        */
    }
    else {
        if(m_connexion_page)
            m_connexion_page->updateStatus("Veuillez patentier lors de la négociation ssl.");
    }
}
void app::signup(QString mail, QString nickname, QString password)
{
    if(m_socket->isEncrypted())
    {
        qDebug() << QString("Envoi d'une demande d'inscription pour %1").arg(nickname);
        signupRequest packet;
        packet.setMail(mail);
        packet.setUser(nickname);
        packet.setPassword(password);
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        packet >> out;
        if(!m_socket->write(data))
                qDebug() << QString("Un problème a eu lieu durant la requête d'inscription pour %1").arg(nickname);
    }
}
void app::requestSendData(message msg)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    msg >> out;
    m_socket->write(data);
}
void app::pendingData()
{
    while(m_socket->bytesAvailable()!=0)
    {
    in.startTransaction();
    quint8 header8bit = 0;
    in >> header8bit;
    packet_type header  = static_cast<packet_type>(header8bit);
    packet * request = nullptr;
    switch(header)
        {
            case packet_type::LOGIN_SUCCESFULL:
            qDebug() << "Authentification réussie.";
            app::open_chat_page();
            break;
            case packet_type::MESSAGE :
            {
             request = new message;
            *request << in;
            }
            break;
            case packet_type::SIGNUP_FAILED :
            {
            if(m_account_creation_page)
            QMessageBox::warning(m_account_creation_page, tr("Echec création de compte"),tr("La création de votre compte a échoué.\nEssayez avec une autre adresse/un autre mot de passe."));
            }
            break;
            case packet_type::LIST:
            {
            qDebug() << "liste reçue";
            request = new listMembers;
            *request << in;
            }
            break;
            case packet_type::SIGNUP_SUCCESFULL:
                open_chat_page();


            break;
            case packet_type::LOGIN_FAILED :
             QMessageBox::warning(m_account_creation_page, tr("Echec authentification"),tr("Votre authentification a échoué.\nEssayez avec une autre adresse/un autre mot de passe."));

            break;
        }
    if(in.commitTransaction())
    {
        switch(header)
            {
            case packet_type::MESSAGE :

             emit newMessage(*(static_cast<message*>(request)));
            break;
             case packet_type::LIST :
             emit refreshList(*(static_cast<listMembers*>(request)));
            break;
            }


    }
    delete request;
    }

}
