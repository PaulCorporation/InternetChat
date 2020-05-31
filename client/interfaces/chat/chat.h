#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>

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
};

#endif // CHAT_H
