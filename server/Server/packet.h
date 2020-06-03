#ifndef PACKET_H
#define PACKET_H
#include <QDataStream>
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
private :
    QString mail;
    QString password;
};
class signupRequest : public packet
{
public:
    signupRequest();
    virtual void operator<<(QDataStream&) override;
    virtual void operator>>(QDataStream&) override;
    QString user;
    QString password;
    QString mail;
};
class message : public packet
{
public:
    message();
    virtual void operator<<(QDataStream&) override;
    virtual void operator>>(QDataStream&) override;
    QString user;
    QString content;
};
#endif // PACKET_H
