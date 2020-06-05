#ifndef ACCOUNT_CREATION_PAGE_H
#define ACCOUNT_CREATION_PAGE_H
#include <QMainWindow>

namespace Ui {
class create_account;
}

class account_creation_page : public QMainWindow
{
    Q_OBJECT
public:
    explicit account_creation_page(QWidget *parent = nullptr);
    ~account_creation_page();
private slots:
    void on_return_2_clicked();
    void on_validate_clicked();

signals:
    void requestConnexionPage();
    void requestSignup(QString, QString, QString);
private:
    Ui::create_account *ui_account_creation_page;
};

#endif // ACCOUNT_CREATION_PAGE_H
