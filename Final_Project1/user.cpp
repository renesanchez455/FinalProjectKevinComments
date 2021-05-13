#include "user.h"

User::User(const QString &ID, const QString &fName, const QString &lName, const QString &passWord, const QString &eAdd, const QString &pNum, const QString &gen, const QString &bDate)
{
    id = ID;
    firstName=fName;
    lastName=lName;
    password = passWord;
    emailAddress=eAdd;
    phoneNo=pNum;
    gender=gen;
    birthDate=bDate;
}

void User::setID(QString ID)
{
    id=ID;
}

QString User::getID()
{
    return id;
}

void User::setPassword(QString passWord)
{
    password=passWord;
}

QString User::getPassword()
{
    return password;
}

void User::setFirstName(QString FName)
{
    firstName = FName;
}

QString User::getFirstName()
{
    return firstName;
}

void User::setLastName(QString LName)
{
    lastName = LName;
}

QString User::getLastName()
{
    return lastName;
}

void User::setEmailAddress(QString eAddress)
{
    emailAddress = eAddress;
}

QString User::getEmailAddress()
{
    return emailAddress;
}

void User::setPhoneNo(QString PNo)
{
    phoneNo = PNo;
}

QString User::getPhoneNo()
{
    return phoneNo;
}

void User::setGender(QString gen)
{
    gender = gen;
}

QString User::getGender()
{
    return gender;
}

void User::setBirthDate(QString bDate)
{
    birthDate = bDate;
}

QString User::getBirthDate()
{
    return birthDate;
}

