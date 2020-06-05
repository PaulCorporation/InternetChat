#ifndef CHATROOM_PAGE_H
#define CHATROOM_PAGE_H
#include <QObject>
#include "interfaces/chat/chat.h"
#include "interfaces/account/account_creation_page.h"
#include "interfaces/connexion/connexion_page.h"
#include <QSslSocket>
class app : public QObject
{
    Q_OBJECT
public:
    app();
    ~app();
private:
    chat *m_chat = nullptr;
    account_creation_page *m_account_creation_page = nullptr;
    connexion_page * m_connexion_page = nullptr;
    QSslSocket *m_socket = nullptr;
    QDataStream in;
    void closeWindows();
public slots :
    void open_account_creation_page();
    void open_connexion_page();
    void open_chat_page();
    void socketAvailable();
    void sslErrors(const QList<QSslError> &errors);
    void login(QString, QString);
    void signup(QString, QString, QString);
    void allow();
    void pendingData();
    void requestSendData(message);
signals :
    void newMessage(message);
    void refreshList(listMembers);
};

#endif // CHATROOM_PAGE_H
