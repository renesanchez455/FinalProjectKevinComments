#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <QString>

class Sequence
{

public:
    Sequence(const QString &, const QString &, const QString &, const QString &, const QString &);
    void setcourseId(QString);
    void setsyllabusId(QString);
    void setProgram(QString);
    void setprogramYear(QString);
    void setSemester(QString);

    QString getcourseId();
    QString getsyllabusId();
    QString getProgram();
    QString getprogramYear();
    QString getSemester();

private:
    QString courseId;
    QString syllabusId;
    QString Program;
    QString programYear;
    QString Semester;
};

#endif // SEQUENCE_H


