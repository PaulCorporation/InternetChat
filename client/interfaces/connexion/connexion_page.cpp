#include "connexion_page.h"
#include "ui_connexion.h"

connexion_page::connexion_page(QWidget *parent) :
    QMainWindow(parent),
    ui_connexion_page(new Ui::connexion)
{
    ui_connexion_page->setupUi(this);
    ui_connexion_page->pass->setEchoMode(QLineEdit::Password);
}

connexion_page::~connexion_page()
{
    delete ui_connexion_page;
}
void connexion_page::on_create_clicked()
{
    emit requestAccountCreationPage();
}

void connexion_page::updateStatus(QString str)
{
    ui_connexion_page->statusBar->showMessage(str, 0);
}

void connexion_page::on_connect_clicked()
{
    emit requestLogin(ui_connexion_page->adress->text(), ui_connexion_page->pass->text());
}

