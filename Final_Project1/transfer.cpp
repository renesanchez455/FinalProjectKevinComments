#include "transfer.h"


Transfer::Transfer(const QString &cId, const QString &grd, const QString &inst)
{
    courseId = cId;
    grade = grd;
    institution = inst;
}

void Transfer::setCourse(QString CID)
{
    courseId = CID;
}

void Transfer::setGrade(QString GRD)
{
    grade = GRD;
}

void Transfer::setInstitution(QString INST)
{
    institution = INST;
}

QString Transfer::getCourse()
{
    return courseId;
}

QString Transfer::getGrade()
{
    return grade;
}

QString Transfer::getInstitution()
{
    return institution;
}




