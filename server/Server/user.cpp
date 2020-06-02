#include "user.h"
#include <QDebug>
user ::user (QSslSocket *socket, quint64 id)
{
    m_socket = socket;
    m_id = id;
}
user ::~user ()
{
}
user::user (const user& usr)
{
    m_socket = usr.m_socket;
    m_id = usr.m_id;
}
QSslSocket* user::getSocket() const
{
    return m_socket;
}
quint64 user::getId() const
{
    return m_id;
}
bool user::operator==(const user& other) const
{
    if(m_id == other.m_id)
       return true;
    else
      return false;

}
