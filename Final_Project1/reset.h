#ifndef RESET_H
#define RESET_H
#include <QString>

class Reset
{
public:
    Reset(const QString &, const QString &, const QString &);
    void setuserId(QString);
    void setnewPwd(QString);
    void setType(QString);

    QString getuserId();
    QString getnewPwd();
    QString getType();

private:
    QString userId;
    QString newPwd;
    QString type;
};

#endif // RESET_H
