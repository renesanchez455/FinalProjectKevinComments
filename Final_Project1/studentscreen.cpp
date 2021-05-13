#include "studentscreen.h"
#include "ui_studentscreen.h"
#include <QMessageBox>

StudentScreen::StudentScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentScreen)
{
    ui->setupUi(this);
    connect(&sus, SIGNAL(hideSFeat()), this, SLOT(hideStudFeat()));
    connect(&rat, SIGNAL(showStudentscr()), this, SLOT(showStudentScrn()));
    connect(&grade, SIGNAL(showStudentscr()), this, SLOT(showStudentScrn()));
}

StudentScreen::~StudentScreen()
{
    delete ui;
}

void StudentScreen::showStudentScrn()
{
    show();
}

void StudentScreen::hideStudFeat()
{
    show();
    ui->addRatingButton->hide();
    ui->viewCSButton->hide();
    QMessageBox msg;
    msg.setWindowTitle("Account Suspended");
    msg.setText("This account is Suspended. Contact Administrator for further assistance.");
    msg.exec();
}

void StudentScreen::on_logOutButton_clicked()
{
    close();
    emit showLogine();
}

void StudentScreen::on_addRatingButton_clicked()
{
    hide();
    rat.show();
    rat.raise();
    rat.activateWindow();
}

void StudentScreen::on_enterGradeButton_clicked()
{
    hide();
    grade.show();
    grade.raise();
    grade.activateWindow();
}


void StudentScreen::on_transferButton_clicked()
{
    hide();
    trans.show();
    trans.raise();
    trans.activateWindow();
}

