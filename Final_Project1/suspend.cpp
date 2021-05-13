#include "suspend.h"

Suspend::Suspend(const QString &uId, const QString &uSt, const QString &tp)
{
    userId = uId;
    type = tp;
    status = uSt;
}

void Suspend::setType(QString t)
{
    type = t;
}

void Suspend::setuserId(QString Uid)
{
    userId = Uid;
}

void Suspend::setuserStatus(QString Ust)
{
    status = Ust;
}

QString Suspend::getType()
{
    return type;
}

QString Suspend::getuserId()
{
    return userId;
}

QString Suspend::getuserStatus()
{
    return status;
}


