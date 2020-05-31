#include "app.h"

app::app()
{
    m_socket = new QSslSocket(this);
    QObject::connect(m_socket, &QSslSocket::encrypted, this, &app::socketAvailable);
    m_socket->connectToHostEncrypted("paulcorporation.space", 12425);
    open_connexion_page();
}


app::~app()
{
    closeWindows();
    m_socket->close();
}


void app::open_account_creation_page() //Open account creation interface
{
    closeWindows();
    m_account_creation_page = new account_creation_page(nullptr);
    m_account_creation_page->show();
    QObject::connect(m_account_creation_page, &account_creation_page::requestConnexionPage, this, &app::open_connexion_page);
}


void app::open_connexion_page() // Open identification interface
{
    closeWindows();
    m_connexion_page = new connexion_page(nullptr);
    m_connexion_page->show();
    QObject::connect(m_connexion_page, &connexion_page::requestAccountCreationPage, this, &app::open_account_creation_page);
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
