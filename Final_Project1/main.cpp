#include <QApplication>
#include "database.h"
#include "admin.h"
#include "loginscreen.h"
#include<QString>
#include<QTranslator>
#include<QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translate;
    QStringList languages;

    languages<<"English"<<"Espanol";
    QString lang = QInputDialog::getItem(NULL, "Select Language", "language", languages);

    if(lang == "Espanol")
    {
        translate.load(":/trans_es.qm");
    }
    if(lang!="English")
    {
        a.installTranslator(&translate);
    }

//    admin m;
//    m.show();
//    m.activateWindow();
    LoginScreen ls;
    ls.show();
    ls.activateWindow();

    Database Dconnect;
    Dconnect.connect();
    return a.exec();
}

