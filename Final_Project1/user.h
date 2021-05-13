#ifndef USER_H
#define USER_H
#include<iostream>
using namespace std;
#include <QString>

class User
{
    friend class Reset;
public:
    User(const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString & );
    void setID(QString);
    QString getID();
    void setFirstName(QString);
    QString getFirstName();
    void setLastName(QString);
    QString getLastName();
    void setPassword(QString);
    QString getPassword();
    void setEmailAddress(QString);
    QString getEmailAddress();
    void setPhoneNo(QString);
    QString getPhoneNo();
    void setGender(QString);
    QString getGender();
    void setBirthDate(QString);
    QString getBirthDate();

private:
    QString id;
    QString firstName;
    QString lastName;
    QString password;
    QString emailAddress;
    QString phoneNo;
    QString gender;
    QString birthDate;
};

#endif // USER_H
