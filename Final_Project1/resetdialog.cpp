#include "resetdialog.h"
#include "ui_resetdialog.h"

Resetdialog::Resetdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Resetdialog)
{
    ui->setupUi(this);
}

Resetdialog::~Resetdialog()
{
    delete ui;
}

void Resetdialog::showResetDialog()
{
    show();
}

void Resetdialog::on_cancelButton_clicked()
{
    Resetdialog::close();
    emit showadmine();
}


void Resetdialog::on_updateButton_clicked()
{
    Userid = ui->userIDLine->text();
    Newpwd = ui->newPasswordLine->text();
    Usertype = type;

    Reset rst(Userid, Newpwd, Usertype);
    db.resetUserPwd(rst);

    ui->userIDLine->clear();
    ui->newPasswordLine->clear();
}


void Resetdialog::on_userTypeComboBox_currentIndexChanged(int index)
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

