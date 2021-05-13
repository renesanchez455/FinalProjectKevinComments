#ifndef GRADE_H
#define GRADE_H
#include <QString>

class Grade
{
public:
    Grade(const QString &, const QString &, const QString &, const QString &);
    void setCourse(QString);
    void setGrade(QString);
    void setYear(QString);
    void studentID(QString);

    QString getCourse();
    QString getGrade();
    QString getYear();
    QString getStudentID();

private:
    QString courseId;
    QString grade;
    QString yr;
    QString studID;

};

#endif // GRADE_H
