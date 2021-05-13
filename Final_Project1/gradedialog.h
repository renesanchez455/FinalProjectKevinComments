#ifndef GRADEDIALOG_H
#define GRADEDIALOG_H
#include "database.h"
#include "grade.h"

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Gradedialog; }
QT_END_NAMESPACE

class Gradedialog : public QDialog
{
    Q_OBJECT

public:
    Gradedialog(QWidget *parent = nullptr);
    ~Gradedialog();

signals:
    void showStudentscr();

public slots:
    void showGradeScrn();

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_CourseComboBox_currentTextChanged(const QString &arg1);

    void on_GradeComboBox_currentTextChanged(const QString &arg1);

    void on_yearComboBox_currentTextChanged(const QString &arg1);

private:
    Ui::Gradedialog *ui;
    Database db;
    QString course;
    QString grade;
    QString year;
    QString sid;
};
#endif // GRADEDIALOG_H
