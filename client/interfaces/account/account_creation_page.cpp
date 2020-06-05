#include "account_creation_page.h"
#include "ui_create_account.h"
account_creation_page::account_creation_page(QWidget *parent) :
    QMainWindow(parent),
    ui_account_creation_page(new Ui::create_account)
{
   ui_account_creation_page->setupUi(this);
   ui_account_creation_page->pass->setEchoMode(QLineEdit::Password);
}

account_creation_page::~account_creation_page()
{
    delete ui_account_creation_page;
}

void account_creation_page::on_return_2_clicked()
{
emit requestConnexionPage();
}

void account_creation_page::on_validate_clicked()
{
    emit requestSignup(ui_account_creation_page->address->text(), ui_account_creation_page->nick->text(), ui_account_creation_page->pass->text());
    ui_account_creation_page->address->setText("");
    ui_account_creation_page->nick->setText("");
    ui_account_creation_page->pass->setText("");
}
