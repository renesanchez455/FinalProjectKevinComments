#include <iostream>
using namespace std;
#include <QString>
#include"Student.h"


Student::Student(const QString &id, const QString &fName, const QString &lName, const QString &pw, const QString &email, const QString &pNo, const QString &gender, const QString &birthDate, const QString &yr)
    :User(id, fName, lName, pw, email, pNo, gender, birthDate)
{
    setYear(yr);
}

void Student::setYear(QString YR)
{
    Year = YR;
}

QString Student::getYear()
{
    return Year;
}
