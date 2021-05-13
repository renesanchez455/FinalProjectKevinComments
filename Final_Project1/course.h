#ifndef COURSE_H
#define COURSE_H
#include <QString>
#include <string>
using std::string;

class Course
{
public:
    Course(const QString &, const QString &, const QString &, const QString &);
    void setcourseId(QString);
    void setcourseName(QString);
    void setnoOfCredits(QString);
    void setcourseDescrip(QString);

    QString getcourseId();
    QString getcourseName();
    QString getnoOfCredits();
    QString getcourseDescrip();

private:
    QString courseId;
    QString courseName;
    QString noOfCredits;
    QString courseDescrip;
};

#endif // COURSE_H

// ID	Syllabus_Id	Program	Program_Year	Semester	Course_Id
