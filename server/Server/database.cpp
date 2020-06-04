#include "database.h"
#include <QSqlDatabase>
#include <QFile>
#include <QCoreApplication>
#include <QDebug>
#include <QXmlStreamReader>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <string>
#include <QDataStream>
#include <QSqlError>
database::database()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    QString hostname;
    QString dbname;
    QString user;
    QString password;
    QFile file ("id.xml");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageLogger(qPrintable("database.cpp"), 13, qPrintable("QFile::open(QIODevice::ReadOnly)")).debug() << "Impossible d'ouvrir le fichier 'id.txt' en lecture.";
        qApp->quit();
    }
    QXmlStreamReader xml;
    xml.setDevice(&file);
    while (!xml.atEnd()) {


           switch(xml.readNext())
           {
                case QXmlStreamReader::StartElement:
                if(xml.name() == "db")
                {
                    auto attrib =  xml.attributes();
                    hostname = attrib.value("hostname").toString();
                    dbname = attrib.value("dbname").toString();
                    user = attrib.value("user").toString();
                    password = attrib.value("password").toString();

                }
                break;
           }
    }
    db.setHostName(hostname);
    db.setDatabaseName(dbname);
    db.setUserName(user);
    db.setPassword(password);
    if(!db.open())
    {
        QMessageLogger(qPrintable("database.cpp"), 44, qPrintable("QSqlDatabase::open()")).debug() << "Impossible de se connecter à a base de données.";
        qApp->quit();
    }
}

bool database::authenticate(QString password, QString mail, QString &name)
{
    QSqlQuery query("SELECT password, name FROM user WHERE mail LIKE :mail", db);
    query.bindValue(":mail", mail);
    query.exec();
    QString storedPassword = query.boundValue("password").toString();
    name = query.boundValue("name").toString();
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(password.toUtf8());
    if(QString(hash.result().toHex()) == storedPassword)
    {
        qDebug() << QString("Successufuly authenticated user %1.").arg(mail);
        return true;
    }
    else
        return false;
}

bool database::signup(QString user, QString mail, QString password)
{
    //We have to verify if an account with the email 'mail' already exists.
    QSqlQuery query(db);
    query.prepare("SELECT count(*) FROM user WHERE mail LIKE :mail;");
    query.bindValue(":mail", mail);
    if(!query.exec())
        {QMessageLogger(qPrintable("database.cpp"), 6, qPrintable("QSqlQuery::exec()")).debug() << query.lastError().text();
        qDebug () << query.lastQuery();
        }
    qDebug() << QString("Ecriture en base");
    if(query.boundValue("count(*)").toInt() == 0)
    {
        qDebug()<<"Aucun autre user du même nom détecté.";
        query.prepare("INSERT INTO user (password, name, mail) VALUES (:password, :name, :mail);");
        query.bindValue(":mail", mail);
        query.bindValue(":name", user);
        QCryptographicHash hash(QCryptographicHash::Sha256);
        hash.addData(password.toUtf8());
        query.bindValue(":password", QString(hash.result().toHex()));
        if(!query.exec())
            QMessageLogger(qPrintable("database.cpp"), 6, qPrintable("QSqlQuery::exec()")).debug() << query.lastError().text();

        return true;
    }
    else {
        qDebug() << "Un utilisateur utilise déjà cette adresse.";
        return false;
    }
}
