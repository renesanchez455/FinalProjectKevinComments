#include "rating.h"



Rating::Rating(const QString &cId, const QString &lId, const QString &ufn, const QString &diff, const QString &cTpe, const QString &enjblty, const QString &yr, const QString &cmmnt, const QString &sem)
{
    courseId = cId;
    lecturerId = lId;
    usefulness = ufn;
    difficulty = diff;
    courseType = cTpe;
    enjoyability = enjblty;
    year = yr;
    comment = cmmnt;
    semester = sem;
}

void Rating::setCourse(QString CID)
{
    courseId = CID;
}

void Rating::setLecturer(QString LID)
{
    lecturerId = LID;

}
void Rating::setUsefulness(QString UFN)
{
    usefulness = UFN;
}
void Rating::setDifficulty(QString DIFF)
{
    difficulty = DIFF;
}
void Rating::setCourseType(QString CTPE)
{
    courseType = CTPE;
}

void Rating::setEnjoyability(QString ENJ)
{
    enjoyability = ENJ;
}

void Rating::setYear(QString YR)
{
    year = YR;
}

void Rating::setComment(QString CMMNT)
{
    comment = CMMNT;
}

void Rating::setSemester(QString SEM)
{
    semester = SEM;
}

QString Rating::getCourse()
{
    return courseId;
}

QString Rating::getLecturer()
{
    return lecturerId;
}

QString Rating::getUsefulness()
{
    return usefulness;
}

QString Rating::getDifficulty()
{
    return difficulty;
}

QString Rating::getCourseType()
{
    return courseType;
}

QString Rating::getEnjoyability()
{
    return enjoyability;
}

QString Rating::getYear()
{
    return year;
}

QString Rating::getComment()
{
    return comment;
}

QString Rating::getSemester()
{
    return semester;
}




