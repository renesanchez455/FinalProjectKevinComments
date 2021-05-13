#include "lecturerscreen.h"
#include "ui_lecturerscreen.h"
#include <QMessageBox>

Lecturerscreen::Lecturerscreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Lecturerscreen)
{
    ui->setupUi(this);
}

Lecturerscreen::~Lecturerscreen()
{
    delete ui;
}

void Lecturerscreen::showLecturerScrn()
{
    show();
}

void Lecturerscreen::hideLecFeat()
{
    show();
    ui->searchstudentButton->hide();
    ui->generatereportButton->hide();
    QMessageBox msg;
    msg.setWindowTitle("Account Suspended");
    msg.setText("This account is Suspended. Contact Administrator for further assistance.");
    msg.exec();
}

void Lecturerscreen::on_logOutButton_clicked()
{
    close();
    emit showLogine();
}


void Lecturerscreen::on_searchstudentButton_clicked()
{
    hide();
    srch.show();
    srch.raise();
    srch.activateWindow();
}

