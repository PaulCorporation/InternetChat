#include "packet.h"

packet::packet()
{

}
loginRequest::loginRequest() : packet()
{
    id=0;
}
signupRequest::signupRequest() : packet()
{
    id=1;
}
message::message() : packet()
{
    id=2;
}

void loginRequest::operator>>(QDataStream& s)
{
    s << quint8(0);
    s << mail;
    s << password;
}
void loginRequest::operator<<(QDataStream& s)
{
    s >> mail;
    s >> password;
}
void signupRequest::operator>>(QDataStream& s)
{
    s << quint8(1);
    s << mail;
    s << password;
    s << user;
}
void signupRequest::operator<<(QDataStream& s)
{
    s >> mail;
    s >> password;
    s >> user;
}
void message::operator>>(QDataStream& s)
{
    s << quint8(2);
    s << content;
    s << user;
}
void message::operator<<(QDataStream& s)
{
    s >> content;
    s >> user;
}
