#ifndef STUDENT_H
#define STUDENT_H
#include "user.h"
#include<iostream>
using namespace std;

class Student : public User
{
public:
    Student(const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &);
    void setYear(QString);

    QString getYear();
private:
    QString Year;

};

#endif // STUDENT_H
