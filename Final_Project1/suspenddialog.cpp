#include "suspenddialog.h"
#include "ui_suspenddialog.h"
#include "suspend.h"

Suspenddialog::Suspenddialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Suspenddialog)
{
    ui->setupUi(this);
}

Suspenddialog::~Suspenddialog()
{
    delete ui;
}

void Suspenddialog::showSuspendDialog()
{
    show();
}


void Suspenddialog::on_cancelButton_clicked()
{
    Suspenddialog::close();
    emit showadmine();
}



void Suspenddialog::on_updateButton_clicked()
{
    Userid = ui->userIDLine->text();
    Usertype = type;
    Userstatus = status;

    Suspend sus(Userid, Userstatus, Usertype);
    db.suspendAccount(sus);
    ui->userIDLine->clear();
}



void Suspenddialog::on_userTypeComboBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        type="null";
    }
    if(index == 1)
    {
        type="student";
    }
    if(index == 2)
    {
        type="lecturer";
    }
}


void Suspenddialog::on_StatusComboBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        status="null";
    }
    if(index == 1)
    {
        status="Active";
    }
    if(index == 2)
    {
        status="Inactive";
    }
}

