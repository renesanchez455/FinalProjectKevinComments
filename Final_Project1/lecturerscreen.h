#ifndef LECTURERSCREEN_H
#define LECTURERSCREEN_H

#include <QDialog>
#include "searchdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Lecturerscreen; }
QT_END_NAMESPACE

class Lecturerscreen : public QDialog
{
    Q_OBJECT

public:
    Lecturerscreen(QWidget *parent = nullptr);
    ~Lecturerscreen();

signals:
    void showLogine();

public slots:
    void showLecturerScrn();
    void hideLecFeat();

private slots:
    void on_logOutButton_clicked();

    void on_searchstudentButton_clicked();

private:
    Ui::Lecturerscreen *ui;
    Searchdialog srch;
};
#endif // LECTURERSCREEN_H
