#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent) :
    QMainWindow(parent),
    ui_chat(new Ui::chat)
{
    ui_chat->setupUi(this);

}

chat::~chat()
{
    delete ui_chat;
}
