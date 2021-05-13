#include "coursedialog.h"
#include "ui_coursedialog.h"
#include "course.h"
#include "database.h"

Coursedialog::Coursedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Coursedialog)
{
    ui->setupUi(this);
}

Coursedialog::~Coursedialog()
{
    delete ui;
}

void Coursedialog::on_cancelButton_clicked()
{
    Coursedialog::close();
    emit showadmine();
}

void Coursedialog::on_registerbutton_clicked()
{
    QString id = ui->courseIdEdit->text();
    QString text = ui->courseNameEdit->text();
    QString credit = ui->creditEdit->text();
    QString descrip = ui->descriptionEdit->toPlainText();
    Course c(id, text, credit, descrip);

    Database db;
    ui->resultLabel->setText(db.insertCourse(c));

    ui->courseIdEdit->clear();
    ui->courseNameEdit->clear();
    ui->creditEdit->clear();
    ui->descriptionEdit->clear();
}


