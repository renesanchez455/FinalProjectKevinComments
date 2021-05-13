#ifndef LECTURERDIALOG_H
#define LECTURERDIALOG_H

#include <QDialog>
#include"database.h"
#include<QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class Lecturerdialog; }
QT_END_NAMESPACE

class Lecturerdialog : public QDialog
{
    Q_OBJECT
signals:
    void showadmine();

public:
    Lecturerdialog(QWidget *parent = nullptr);
    ~Lecturerdialog();
signals:
    void lecturerObj();
private slots:
    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::Lecturerdialog *ui;
    QString LID;
    QString Fname;
    QString Lname;
    QString Pwd;
    QString Email;
    QString Pno;
    QString DOB;
    QString Gender;

    Database db;


};
#endif // LECTURERDIALOG_H
