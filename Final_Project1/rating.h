#ifndef RATING_H
#define RATING_H
#include <QString>

class Rating
{
public:
    Rating(const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &);
    void setCourse(QString);
    void setLecturer(QString);
    void setUsefulness(QString);
    void setDifficulty(QString);
    void setCourseType(QString);
    void setEnjoyability(QString);
    void setYear(QString);
    void setComment(QString);
    void setSemester(QString);

    QString getCourse();
    QString getLecturer();
    QString getUsefulness();
    QString getDifficulty();
    QString getCourseType();
    QString getEnjoyability();
    QString getYear();
    QString getComment();
    QString getSemester();

private:
    QString courseId;
    QString lecturerId;
    QString usefulness;
    QString difficulty;
    QString courseType;
    QString enjoyability;
    QString year;
    QString comment;
    QString semester;
};

#endif // RATING_H
