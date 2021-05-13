#include "transferdialog.h"
#include "ui_transferdialog.h"

Transferdialog::Transferdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Transferdialog)
{
    ui->setupUi(this);
}

Transferdialog::~Transferdialog()
{
    delete ui;
}

void Transferdialog::showTransScrn()
{
    show();
}


void Transferdialog::on_okButton_clicked()
{

}


void Transferdialog::on_cancelButton_clicked()
{
    close();
    emit showStudentscr();
}


void Transferdialog::on_courseComboBox_currentTextChanged(const QString &arg1)
{

}

