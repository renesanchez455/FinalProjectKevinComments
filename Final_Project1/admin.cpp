#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin)
{
    ui->setupUi(this);

    connect(&lecturer, SIGNAL(showadmine()), this, SLOT(showAdmin()));
    connect(&course, SIGNAL(showadmine()), this, SLOT(showAdmin()));
    connect(&seq, SIGNAL(showadmine()), this, SLOT(showAdmin()));
    connect(&reset, SIGNAL(showadmine()), this, SLOT(showAdmin()));
    connect(&suspend, SIGNAL(showadmine()), this, SLOT(showAdmin()));

    //connect signals created from lecturer and student here with the data...
}

admin::~admin()
{
    delete ui;
}

void admin::on_newlecturerbutton_clicked()
{
    lecturer.show();
    lecturer.raise();
    lecturer.activateWindow();

    hide();
}

void admin::on_newcoursebutton_clicked()
{
    course.show();
    course.raise();
    course.activateWindow();

    hide();
}

void admin::showAdmin()
{
    show();
    raise();
    activateWindow();
}

void admin::on_logOutButton_clicked()
{
    close();
    emit showLogine();
}

void admin::on_newsequencebutton_clicked()
{
    hide();
    seq.show();
    seq.raise();
    seq.activateWindow();
}

void admin::on_rupwdButton_clicked()
{
    hide();
    reset.show();
    reset.raise();
    reset.activateWindow();
}


void admin::on_suspaccButton_clicked()
{
    hide();
    suspend.show();
    suspend.raise();
    suspend.activateWindow();
}


void admin::on_genderChartButton_clicked()
{

}
