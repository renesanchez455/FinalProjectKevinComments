#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include "Student.h"
#include "lecturer.h"
#include "course.h"
#include "searchdialog.h"
#include "ui_searchdialog.h"
#include "ui_loginscreen.h"
#include "sequence.h"
#include "reset.h"
#include "suspend.h"
#include "rating.h"
#include "grade.h"

namespace Ui {
class Database;

}
class Database
{
public:
    Database();
    QString insertStudent(Student );
    QString insertLecturer(Lecturer);
    QString insertCourse(Course);
    void findStudent(QString );
    QString resetUserPwd(Reset);
    QString suspendAccount(Suspend);
    QString insertSequence(Sequence);
    QString verifyLogin(QString, QString, QString);
    QString insertRating(Rating);
    QStringList totalGenders();
    QString insertGrade(Grade);


    friend void closeDB(Database &); //Friend function

signals:
    void showStudentScrn();
    void showLecturerScrn();
    void showAdminScrn();

public slots:
    void connect();
    void disconnectDB();

private:
    QSqlDatabase db;
    Ui::Searchdialog *sd;
    Ui::LoginScreen *lg;
    bool connected;
    QString currentID;
    QString status;
};

#endif // DATABASE_H
