#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include "packet.h"
namespace Ui {
class chat;
}

class chat : public QMainWindow
{
    Q_OBJECT
public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();
private:
    Ui::chat *ui_chat;
signals:
    void requestToSend(message);
private slots:
    void on_pushButton_clicked();
public slots:
    void newMessage(message);
    void refreshList(listMembers);
};

#endif // CHAT_H
