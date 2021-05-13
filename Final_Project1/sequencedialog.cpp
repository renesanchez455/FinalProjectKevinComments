#include "sequencedialog.h"
#include "ui_sequencedialog.h"

Sequencedialog::Sequencedialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Sequencedialog)
{
    ui->setupUi(this);
}

Sequencedialog::~Sequencedialog()
{
    delete ui;
}
void Sequencedialog::on_addButton_clicked()
{
    qDebug()<<course;
    syllabusId = ui->syllabusIdEdit->text();

    Sequence seq(syllabusId, program, progYear, semester, course);
    ui->resultLabel->setText(db.insertSequence(seq));
}
void Sequencedialog::on_ProgramComboBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        program="";
    }
    if(index == 1)
    {
        program="AINT";
    }
    if(index == 2)
    {
        program="BINT";
    }
}

void Sequencedialog::on_SemesterComboBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        semester="";
    }
    if(index == 1)
    {
        semester="1";
    }
    if(index == 2)
    {
        semester="2";
    }
}

void Sequencedialog::on_cancelButton_clicked()
{
    close();
    emit showadmine();
}

void Sequencedialog::on_CourseComboBox_currentTextChanged(const QString &arg1)
{
    course=arg1;
}


void Sequencedialog::on_progYearComboBox_currentTextChanged(const QString &arg1)
{
    progYear=arg1;
}
