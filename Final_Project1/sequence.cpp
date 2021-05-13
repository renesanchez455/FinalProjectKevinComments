#include "sequence.h"

Sequence::Sequence(const QString &sId, const QString &prog, const QString &progY, const QString &sem, const QString &cId)
{
    syllabusId = sId;
    Program = prog;
    programYear = progY;
    Semester = sem;
    courseId = cId;
}
void Sequence::setcourseId(QString crsID)
{
    courseId = crsID;
}

void Sequence::setsyllabusId(QString syllID)
{
    syllabusId = syllID;
}

void Sequence::setProgram(QString Prog)
{
    Program = Prog;
}

void Sequence::setprogramYear(QString progrY)
{
    programYear = progrY;
}

void Sequence::setSemester(QString Smstr)
{
    Semester = Smstr;
}

QString Sequence::getcourseId()
{
    return courseId;
}

QString Sequence::getsyllabusId()
{
    return syllabusId;
}

QString Sequence::getProgram()
{
    return Program;
}

QString Sequence::getprogramYear()
{
    return programYear;
}

QString Sequence::getSemester()
{
    return Semester;
}


