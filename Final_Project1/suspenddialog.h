#ifndef SUSPENDDIALOG_H
#define SUSPENDDIALOG_H
#include "database.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Suspenddialog; }
QT_END_NAMESPACE

class Suspenddialog : public QDialog
{
    Q_OBJECT

public:
    Suspenddialog(QWidget *parent = nullptr);
    ~Suspenddialog();

signals:
    void showadmine();
    void hideSFeat();

public slots:
    void showSuspendDialog();

private slots:
    void on_cancelButton_clicked();

    void on_updateButton_clicked();

    void on_userTypeComboBox_currentIndexChanged(int index);

    void on_StatusComboBox_currentIndexChanged(int index);

private:
    Ui::Suspenddialog *ui;
    QString Userid;

    QString Usertype;
    QString type;

    QString Userstatus;
    QString status;

    Database db;

};
#endif // SUSPENDDIALOG_H
