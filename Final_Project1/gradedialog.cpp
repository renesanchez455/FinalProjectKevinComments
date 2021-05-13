#include "gradedialog.h"
#include "ui_gradedialog.h"

Gradedialog::Gradedialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Gradedialog)
{
    ui->setupUi(this);
}

Gradedialog::~Gradedialog()
{
    delete ui;
}

void Gradedialog::showGradeScrn()
{
    show();
}


void Gradedialog::on_okButton_clicked()
{
    sid = ui->studentIDEdit->text();
    Grade grd(course, grade, year, sid);
    ui->resultLabel->setText(db.insertGrade(grd));

    ui->studentIDEdit->clear();
}


void Gradedialog::on_cancelButton_clicked()
{
    close();
    emit showStudentscr();
}


void Gradedialog::on_CourseComboBox_currentTextChanged(const QString &arg1)
{
    course = arg1;
}

void Gradedialog::on_GradeComboBox_currentTextChanged(const QString &arg1)
{
    grade = arg1;
}

void Gradedialog::on_yearComboBox_currentTextChanged(const QString &arg1)
{
    year = arg1;
}

