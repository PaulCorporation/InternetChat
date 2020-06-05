#ifndef PACKET_H
#define PACKET_H
#include <QDataStream>
#include <QVector>
/*
each classes here provide an easy interface for data serialization between clients and server.
Each request reimplement the operator << and >> to directly serialize him components in a QDataStream
*/

enum class packet_type
{
    LOGIN_REQUEST =0, SIGNUP_REQUEST, MESSAGE, LOGIN_SUCCESFULL,SIGNUP_SUCCESFULL,LOGIN_FAILED, SIGNUP_FAILED, LIST
};

class packet
{
public:
    packet();
    virtual void operator<<(QDataStream&) = 0;
    virtual void operator>>(QDataStream&) = 0;
protected:
    quint8 id;
};
class loginRequest : public packet
{
public:
    loginRequest();
    virtual void operator<<(QDataStream&) override;
    virtual void operator>>(QDataStream&) override;
    void setMail(QString mail);
    void setPassword(QString password);
    QString getMail();
    QString getPassword();
private :
    QString m_mail;
    QString m_password;
};
class signupRequest : public packet
{
public:
    signupRequest();
    virtual void operator<<(QDataStream&) override;
    virtual void operator>>(QDataStream&) override;
    void setMail(QString mail);
    void setPassword(QString password);
    void setUser(QString user);
    QString getMail();
    QString getPassword();
    QString getUser();
    QString m_user;
    QString m_password;
    QString m_mail;
};
class message : public packet
{
public:
    message();
    virtual void operator<<(QDataStream&) override;
    virtual void operator>>(QDataStream&) override;
    void setUser(QString user);
    void setContent(QString content);
    QString getUser();
    QString getContent();
    QString m_user;
    QString m_content;
};
class listMembers : public packet
{
public:
    listMembers();
    virtual void operator<<(QDataStream&) override;
    virtual void operator>>(QDataStream&) override;
    void addMember(QString);
    QVector<QString> getMembers();
private:
    QVector<QString> m_names;
};
#endif // PACKET_H
