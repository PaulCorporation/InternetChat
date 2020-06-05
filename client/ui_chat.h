/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QAction *actioncolortion;
    QAction *actionsauvegarder;
    QAction *action_propos;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QListWidget *listWidget_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuOutils;
    QMenu *menu_propos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QStringLiteral("chat"));
        chat->resize(344, 215);
        actioncolortion = new QAction(chat);
        actioncolortion->setObjectName(QStringLiteral("actioncolortion"));
        actionsauvegarder = new QAction(chat);
        actionsauvegarder->setObjectName(QStringLiteral("actionsauvegarder"));
        action_propos = new QAction(chat);
        action_propos->setObjectName(QStringLiteral("action_propos"));
        centralwidget = new QWidget(chat);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));

        verticalLayout_3->addWidget(listWidget_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        chat->setCentralWidget(centralwidget);
        menubar = new QMenuBar(chat);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 344, 22));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuOutils = new QMenu(menubar);
        menuOutils->setObjectName(QStringLiteral("menuOutils"));
        menu_propos = new QMenu(menubar);
        menu_propos->setObjectName(QStringLiteral("menu_propos"));
        chat->setMenuBar(menubar);
        statusbar = new QStatusBar(chat);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        chat->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuOutils->menuAction());
        menubar->addAction(menu_propos->menuAction());
        menuFichier->addAction(actionsauvegarder);
        menuOutils->addAction(actioncolortion);
        menu_propos->addAction(action_propos);

        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QMainWindow *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "En ligne", nullptr));
        actioncolortion->setText(QApplication::translate("chat", "coloration", nullptr));
        actionsauvegarder->setText(QApplication::translate("chat", "sauvegarder", nullptr));
        action_propos->setText(QApplication::translate("chat", "\303\200 propos", nullptr));
        label->setText(QApplication::translate("chat", "Messages", nullptr));
        label_2->setText(QApplication::translate("chat", "Membres", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("chat", "Votre message", nullptr));
        pushButton->setText(QApplication::translate("chat", "Envoyer", nullptr));
        menuFichier->setTitle(QApplication::translate("chat", "Fichier", nullptr));
        menuOutils->setTitle(QApplication::translate("chat", "Outils", nullptr));
        menu_propos->setTitle(QApplication::translate("chat", "\303\200 propos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
