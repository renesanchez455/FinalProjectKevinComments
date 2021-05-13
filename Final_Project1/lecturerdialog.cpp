#include "lecturerdialog.h"
#include "ui_lecturerdialog.h"

#include "lecturer.h"
#include "database.h"

Lecturerdialog::Lecturerdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Lecturerdialog)
{
    ui->setupUi(this);
}

Lecturerdialog::~Lecturerdialog()
{
    delete ui;
}

void Lecturerdialog::on_cancelButton_clicked()
{
    Lecturerdialog::close();

    emit showadmine();
}

void Lecturerdialog::on_okButton_clicked()
{
    LID = ui->lecturerIDLine->text();
    Fname = ui->lecturerFNLine->text();
    Lname = ui->lecturerLNLine->text();
    Pwd = ui->lecturerPasswordLine->text();
    Email = ui->lecturerEmailLine->text();
    Pno = ui->lecturerPhoneLine->text();
    DOB = ui->lecturerDOBBox->text();
    Gender = ui->lecturerGenderLine->text();

    Lecturer lec(LID, Fname, Lname, Pwd, Email, Pno, DOB, Gender);
    ui->resultLabel->setText(db.insertLecturer(lec));

    ui->lecturerIDLine->clear();
    ui->lecturerFNLine->clear();
    ui->lecturerLNLine->clear();
    ui->lecturerPasswordLine->clear();
    ui->lecturerEmailLine->clear();
    ui->lecturerPhoneLine->clear();
    ui->lecturerDOBBox->clear();
    ui->lecturerGenderLine->clear();
}
