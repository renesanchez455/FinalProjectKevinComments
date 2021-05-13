#include "searchdialog.h"
#include "ui_searchdialog.h"
#include "database.h"

Searchdialog::Searchdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Searchdialog)
{
    ui->setupUi(this);

}

Searchdialog::~Searchdialog()
{
    delete ui;
}

void Searchdialog::dsiplaySearchData(QString f)
{
//    ui->idlinestuff->setText(f);
}


void Searchdialog::on_cancelButton_clicked()
{
    Searchdialog::close();
    emit showadmine();
}

void Searchdialog::on_searchButton_clicked()
{
    Database db;
    QString Id= ui->idLine->text();
    db.findStudent(Id);
}
