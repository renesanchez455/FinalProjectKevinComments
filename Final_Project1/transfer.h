#ifndef TRANSFER_H
#define TRANSFER_H
#include <QString>

class Transfer
{
public:
    Transfer(const QString &, const QString &, const QString &);
    void setCourse(QString);
    void setGrade(QString);
    void setInstitution(QString);

    QString getCourse();
    QString getGrade();
    QString getInstitution();

private:
    QString courseId;
    QString grade;
    QString institution;
};

#endif // TRANSFER_H
