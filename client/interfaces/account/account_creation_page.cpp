#include "account_creation_page.h"
#include "ui_create_account.h"

account_creation_page::account_creation_page(QWidget *parent) :
    QMainWindow(parent),
    ui_account_creation_page(new Ui::create_account)
{
   ui_account_creation_page->setupUi(this);

}

account_creation_page::~account_creation_page()
{
    delete ui_account_creation_page;
}

void account_creation_page::on_return_2_clicked()
{
emit requestConnexionPage();
}
