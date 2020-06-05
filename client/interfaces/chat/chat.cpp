#include "chat.h"
#include "ui_chat.h"
#include <QMessageBox>
#include <QDebug>
chat::chat(QWidget *parent) :
    QMainWindow(parent),
    ui_chat(new Ui::chat)
{
    ui_chat->setupUi(this);
    QMessageBox::information(this, tr("Authentification effectuée"),
                             tr("Vous êtes authentifié sur le serveur.\nVous pouvez désormais communiquer avec les autres utilisateurs."));
}

chat::~chat()
{
    delete ui_chat;
}

void chat::on_pushButton_clicked()
{
message msg;
msg.setContent(ui_chat->lineEdit->text());
msg.setUser("usr");
emit requestToSend(msg);
ui_chat->lineEdit->setText("");
}
void chat::newMessage(message msg)
{
qDebug() << "nouveau message";
ui_chat->listWidget->addItem(msg.getUser() + " | " + msg.getContent());

}
void chat::refreshList(listMembers list)
{
    ui_chat->listWidget_2->clear();
    QVector<QString> noms = list.getMembers();
    for(auto it = noms.begin(); it != noms.end(); ++it)
    {
    ui_chat->listWidget_2->addItem(*it);
    }
}
