#ifndef SEQUENCEDIALOG_H
#define SEQUENCEDIALOG_H

#include <QDialog>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Sequencedialog; }
QT_END_NAMESPACE

class Sequencedialog : public QDialog
{
    Q_OBJECT

public:
    Sequencedialog(QWidget *parent = nullptr);
    ~Sequencedialog();
signals:
    void showadmine();

private slots:
    void on_addButton_clicked();

    void on_ProgramComboBox_currentIndexChanged(int index);
    void on_SemesterComboBox_currentIndexChanged(int index);
    void on_cancelButton_clicked();
    void on_CourseComboBox_currentTextChanged(const QString &arg1);

    void on_progYearComboBox_currentTextChanged(const QString &arg1);

private:
    Ui::Sequencedialog *ui;
    Database db;
    QString syllabusId;
    QString progYear;
    QString course;
    QString program;
    QString semester;
};
#endif // SEQUENCEDIALOG_H
