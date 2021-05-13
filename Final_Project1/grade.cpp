#include "grade.h"

Grade::Grade(const QString &cId, const QString &grd, const QString &year, const QString &sId)
{
    courseId = cId;
    grade = grd;
    yr = year;
    studID = sId;
}

void Grade::setCourse(QString Courseid)
{
    courseId = Courseid;
}

void Grade::setGrade(QString Grd)
{
    grade = Grd;
}

void Grade::setYear(QString Yr)
{
    yr = Yr;
}

void Grade::studentID(QString Sid)
{
    studID = Sid;
}

QString Grade::getCourse()
{
    return courseId;
}

QString Grade::getGrade()
{
    return grade;
}

QString Grade::getYear()
{
    return yr;
}

QString Grade::getStudentID()
{
    return studID;
}
