#ifndef SUSPEND_H
#define SUSPEND_H
#include <QString>

class Suspend
{
public:
    Suspend(const QString &, const QString &, const QString &);
    void setType(QString);
    void setuserId(QString);
    void setuserStatus(QString);

    QString getType();
    QString getuserId();
    QString getuserStatus();

private:
    QString type;
    QString userId;
    QString status;
};

#endif // SUSPEND_H
