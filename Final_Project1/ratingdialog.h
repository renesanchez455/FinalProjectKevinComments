#ifndef RATINGDIALOG_H
#define RATINGDIALOG_H
#include "rating.h"
#include "database.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Ratingdialog; }
QT_END_NAMESPACE

class Ratingdialog : public QDialog
{
    Q_OBJECT

public:
    Ratingdialog(QWidget *parent = nullptr);
    ~Ratingdialog();

signals:
    void showStudentscr();

public slots:
    void showRatingScrn();

private slots:
    void on_courseComboBox_currentTextChanged(const QString &arg1);

    void on_lecturerComboBox_currentTextChanged(const QString &arg1);

    void on_usefulnessComboBox_currentTextChanged(const QString &arg1);

    void on_difficultyComboBox_currentTextChanged(const QString &arg1);

    void on_courseTypeComboBox_2_currentTextChanged(const QString &arg1);

    void on_enjoyabilityComboBox_3_currentTextChanged(const QString &arg1);

    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_semesterComboBox_currentIndexChanged(int index);

    void on_yearComboBox_currentTextChanged(const QString &arg1);

private:
    Ui::Ratingdialog *ui;
    QString course;
    QString lecturer;
    QString usefulness;
    QString difficulty;
    QString courseType;
    QString enjoyability;
    QString year;
    QString semester;
    Database db;
};
#endif // RATINGDIALOG_H
