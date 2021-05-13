#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H
#include <QMainWindow>
#include "database.h"
#include "studentscreen.h"
#include "lecturerscreen.h"
#include "admin.h"
#include "studentdialog.h"
#include "ui_studentdialog.h"



QT_BEGIN_NAMESPACE
namespace Ui { class LoginScreen; }
QT_END_NAMESPACE

class LoginScreen : public QMainWindow
{
    Q_OBJECT
protected:
   void changeEvent(QEvent * event) override;

public:
    LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();
    void closeDB(Database &db);

  public slots:
    void on_qEspanol_triggered();
    void on_qEnglish_triggered();

signals:
    void showStudent();

private slots:
    void on_cancelButton_clicked();
    void on_loginButton_clicked();
    void on_userComboBox_currentIndexChanged(int index);
    void showLogin();

    void on_registerStudentButton_clicked();

private:
    Ui::LoginScreen *ui;
    QString type;
    Database db;
    StudentScreen sscr;
    Lecturerscreen lscr;
    admin ascr;
    Studentdialog addstud;
    QTranslator translate;
    QTranslator qtLanguageTranslator;


};
#endif // LOGINSCREEN_H
