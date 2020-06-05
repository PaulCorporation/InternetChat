#include "packet.h"

packet::packet()
{

}
loginRequest::loginRequest() : packet()
{
    id=static_cast<quint8>(packet_type::LOGIN_REQUEST);
}
signupRequest::signupRequest() : packet()
{
    id=static_cast<quint8>(packet_type::SIGNUP_REQUEST);
}
message::message() : packet()
{
    id=static_cast<quint8>(packet_type::MESSAGE);
}

void loginRequest::operator>>(QDataStream& s)
{
    s << id;
    s << m_mail;
    s << m_password;
}
void loginRequest::operator<<(QDataStream& s)
{
    s >> m_mail;
    s >> m_password;
}
void loginRequest::setMail(QString mail)
{
    m_mail = mail;
}
void loginRequest::setPassword(QString password)
{
    m_password = password;
}
QString loginRequest::getMail()
{
    return m_mail;
}
QString loginRequest::getPassword()
{
    return m_password;
}
void signupRequest::operator>>(QDataStream& s)
{
    s << id;
    s << m_mail;
    s << m_password;
    s << m_user;
}
void signupRequest::operator<<(QDataStream& s)
{
    s >> m_mail;
    s >> m_password;
    s >> m_user;
}
void signupRequest::setMail(QString mail)
{
    m_mail = mail;
}
void signupRequest::setPassword(QString password)
{
    m_password = password;
}
void signupRequest::setUser(QString user)
{
    m_user = user;
}
QString signupRequest::getMail()
{
    return m_mail;
}
QString signupRequest::getPassword()
{
    return m_password;
}
QString signupRequest::getUser()
{
    return m_user;
}
void message::operator>>(QDataStream& s)
{
    s << id;
    s << m_content;
    s << m_user;
}
void message::operator<<(QDataStream& s)
{
    s >> m_content;
    s >> m_user;
}
void message::setUser(QString user)
{
    m_user = user;
}
void message::setContent(QString content)
{
    m_content = content;
}
QString message::getUser()
{
    return m_user;
}
QString message::getContent()
{
    return m_content;
}
listMembers::listMembers()
{
    id==static_cast<quint8>(packet_type::LIST);
}
void listMembers::operator<<(QDataStream& s)
{
    quint16 size;
    s >> size;
    for(unsigned int it = 0; it < size; ++it)
    {
    QString name;
    s >> name;
    m_names.push_back(name);
    }
}
void listMembers::operator>>(QDataStream& s)
{
    s << id;
    s << quint16(m_names.size());
    for(auto it = m_names.begin(); it!= m_names.end(); ++it)
    {
    s << *it;
    }
}
void listMembers::addMember(QString name)
{
    m_names.push_back(name);
}
QVector<QString> listMembers::getMembers()
{
    return m_names;
}
