#ifndef ADMIN_H
#define ADMIN_H
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDialog>

#include "sequencedialog.h"
#include "lecturerdialog.h"
#include "ui_lecturerdialog.h"
#include "studentdialog.h"
#include "ui_studentdialog.h"

#include "coursedialog.h"
#include "ui_coursedialog.h"

#include "searchdialog.h"
#include "ui_searchdialog.h"

#include "resetdialog.h"
#include "ui_resetdialog.h"

#include "suspenddialog.h"
#include "ui_suspenddialog.h"

#include"database.h"


//rene sanchez jsadfdafl;ksdfjdsl;fakflaf


QT_BEGIN_NAMESPACE

namespace Ui { class admin; }
QT_END_NAMESPACE

class admin : public QDialog
{
    Q_OBJECT

public:
    admin(QWidget *parent = nullptr);
    ~admin();

signals:
    void showLogine();

private slots:
    void on_newlecturerbutton_clicked();
    void on_newcoursebutton_clicked();
    void showAdmin();
    void on_logOutButton_clicked();
    void on_newsequencebutton_clicked();
    void on_rupwdButton_clicked();
    void on_genderChartButton_clicked();



    void on_suspaccButton_clicked();



private:
    Ui::admin *ui;
    QSqlDatabase db;
    bool connected;
    int currentID;
    Database Dconnect;
    Lecturerdialog lecturer;
    Studentdialog student;
    Searchdialog search;
    Coursedialog course;
    Sequencedialog seq;
    Resetdialog reset;
    Suspenddialog suspend;

};
#endif // ADMIN_H
