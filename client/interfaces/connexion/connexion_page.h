#ifndef CONNEXION_PAGE_H
#define CONNEXION_PAGE_H
#include <QMainWindow>

namespace Ui {
class connexion;
}

class connexion_page : public QMainWindow
{
    Q_OBJECT
public:
    explicit connexion_page(QWidget *parent = nullptr);
    void updateStatus(QString str);
    ~connexion_page();

private slots:
    void on_create_clicked();
signals :
    void requestAccountCreationPage();
private:
    Ui::connexion *ui_connexion_page;
};

#endif // CONNEXION_PAGE_H
