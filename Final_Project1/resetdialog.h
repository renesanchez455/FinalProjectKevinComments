#ifndef RESETDIALOG_H
#define RESETDIALOG_H
#include "database.h"
#include "reset.h"
#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Resetdialog; }
QT_END_NAMESPACE

class Resetdialog : public QDialog
{
    Q_OBJECT

public:
    Resetdialog(QWidget *parent = nullptr);
    ~Resetdialog();

signals:
    void showadmine();

public slots:
    void showResetDialog();

private slots:
    void on_cancelButton_clicked();

    void on_updateButton_clicked();

    void on_userTypeComboBox_currentIndexChanged(int index);

private:
    Ui::Resetdialog *ui;
    QString Userid;
    QString Newpwd;
    QString Usertype;
    QString type;
    Database db;
};
#endif // RESETDIALOG_H
