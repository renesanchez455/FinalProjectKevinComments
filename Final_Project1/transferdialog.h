#ifndef TRANSFERDIALOG_H
#define TRANSFERDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Transferdialog; }
QT_END_NAMESPACE

class Transferdialog : public QDialog
{
    Q_OBJECT

public:
    Transferdialog(QWidget *parent = nullptr);
    ~Transferdialog();

signals:
    void showStudentscr();

public slots:
    void showTransScrn();


private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_courseComboBox_currentTextChanged(const QString &arg1);

private:
    Ui::Transferdialog *ui;
};
#endif // TRANSFERDIALOG_H
