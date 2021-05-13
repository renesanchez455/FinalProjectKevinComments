#ifndef COURSEDIALOG_H
#define COURSEDIALOG_H

#include <QDialog>

namespace Ui {
class Coursedialog;
}

class Coursedialog : public QDialog
{
    Q_OBJECT

public:
    explicit Coursedialog(QWidget *parent = nullptr);
    ~Coursedialog();

signals:
    void showadmine();

private slots:
    void on_cancelButton_clicked();
    void on_registerbutton_clicked();

private:
    Ui::Coursedialog *ui;
};

#endif // COURSEDIALOG_H
