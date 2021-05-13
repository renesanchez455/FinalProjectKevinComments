#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Searchdialog; }
QT_END_NAMESPACE

class Searchdialog : public QDialog
{
    Q_OBJECT

public:
    Searchdialog(QWidget *parent = nullptr);
    ~Searchdialog();
signals:
    void showadmine();
public slots:
    void dsiplaySearchData(QString);

private slots:
    void on_cancelButton_clicked();
    void on_searchButton_clicked();


private:
    Ui::Searchdialog *ui;

};
#endif // SEARCHDIALOG_H
