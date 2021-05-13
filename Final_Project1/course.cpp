#include "course.h"

Course::Course(const QString &cId, const QString &courseN, const QString &cred, const QString &descrp)
{
    courseId=cId;
    courseName=courseN;
    noOfCredits=cred;
    courseDescrip=descrp;
}

void Course::setcourseId(QString i)
{
    courseId =i;
}

void Course::setcourseName(QString j)
{
    courseName=j;
}

void Course::setnoOfCredits(QString k)
{
    noOfCredits=k;
}

void Course::setcourseDescrip(QString l)
{
    courseDescrip=l;
}

QString Course::getcourseId()
{
    return courseId;
}

QString Course::getcourseName()
{
    return courseName;
}

QString Course::getnoOfCredits()
{
    return noOfCredits;
}

QString Course::getcourseDescrip()
{
    return courseDescrip;
}
