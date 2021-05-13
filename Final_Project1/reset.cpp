#include "reset.h"

Reset::Reset(const QString &uId, const QString &nPwd, const QString &tp)
{
    userId = uId;
    newPwd = nPwd;
    type = tp;
}

void Reset::setuserId(QString Uid)
{
    userId = Uid;
}

void Reset::setnewPwd(QString newP)
{
    newPwd = newP;
}

void Reset::setType(QString t)
{
    type = t;
}

QString Reset::getuserId()
{
    return userId;
}

QString Reset::getnewPwd()
{
    return newPwd;
}

QString Reset::getType()
{
    return type;
}

