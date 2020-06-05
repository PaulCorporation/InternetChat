/********************************************************************************
** Form generated from reading UI file 'create_account.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_ACCOUNT_H
#define UI_CREATE_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_create_account
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QLineEdit *nick;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *address;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_3;
    QLineEdit *pass;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *return_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *validate;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *create_account)
    {
        if (create_account->objectName().isEmpty())
            create_account->setObjectName(QStringLiteral("create_account"));
        create_account->resize(419, 308);
        centralwidget = new QWidget(create_account);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        nick = new QLineEdit(centralwidget);
        nick->setObjectName(QStringLiteral("nick"));

        horizontalLayout_2->addWidget(nick);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        address = new QLineEdit(centralwidget);
        address->setObjectName(QStringLiteral("address"));

        gridLayout->addWidget(address, 0, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        pass = new QLineEdit(centralwidget);
        pass->setObjectName(QStringLiteral("pass"));

        horizontalLayout_3->addWidget(pass);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        return_2 = new QPushButton(centralwidget);
        return_2->setObjectName(QStringLiteral("return_2"));

        horizontalLayout->addWidget(return_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        validate = new QPushButton(centralwidget);
        validate->setObjectName(QStringLiteral("validate"));

        horizontalLayout->addWidget(validate);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        create_account->setCentralWidget(centralwidget);
        menubar = new QMenuBar(create_account);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 419, 22));
        create_account->setMenuBar(menubar);
        statusbar = new QStatusBar(create_account);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        create_account->setStatusBar(statusbar);

        retranslateUi(create_account);

        QMetaObject::connectSlotsByName(create_account);
    } // setupUi

    void retranslateUi(QMainWindow *create_account)
    {
        create_account->setWindowTitle(QApplication::translate("create_account", "Cr\303\251er un compte", nullptr));
        label->setText(QApplication::translate("create_account", "Pseudo", nullptr));
        label_2->setText(QApplication::translate("create_account", "Adresse", nullptr));
        label_3->setText(QApplication::translate("create_account", "Mot de passe", nullptr));
        return_2->setText(QApplication::translate("create_account", "Retour", nullptr));
        validate->setText(QApplication::translate("create_account", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class create_account: public Ui_create_account {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_ACCOUNT_H
