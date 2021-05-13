#include "database.h"
#include "lecturerdialog.h"
#include "loginscreen.h"
#include "studentscreen.h"
#include<QDebug>
#include"user.h"
#include <QSqlRecord>
#include "loginscreen.h"
#include "studentscreen.h"
#include <QMessageBox>

Database::Database()
{

}

QString Database::insertStudent(Student s)
{
    QString FirstName = s.getFirstName();
    QString LastName = s.getLastName();
    QString Gender = s.getGender();
    QString Student_id = s.getID();
    QString BirthDate = s.getBirthDate();
    QString EmailAddress = s.getEmailAddress();
    QString Password = s.getPassword();
    QString Phone_No = s.getPhoneNo();
    QString Year = s.getYear();
    QString res;

    try{
        if(FirstName.isEmpty() || LastName.isEmpty() || Gender.isEmpty() || Student_id.isEmpty() || BirthDate.isEmpty() || EmailAddress.isEmpty() || Password.isEmpty() || Phone_No.isEmpty() || Year.isEmpty())
        {
            throw "A field is empty!! Please fill in all areas";
        }

        qDebug() << "INSERT INTO student (FirstName, LastName, Gender, Student_Id, BirthDate, EmailAddress, Password, Phone_No, Year) VALUES "
                    "('" + FirstName + "','" + LastName + "','" + Gender + "','" + Student_id + "','" + BirthDate + "','" + EmailAddress + "','" + Password + "','" + Phone_No + "')";
        QSqlQuery query;
        if (query.exec("INSERT INTO student (FirstName, LastName, Gender, Student_Id, BirthDate, EmailAddress, Password, Phone_No, Year) VALUES "
                       "('" + FirstName + "','" + LastName + "','" + Gender + "','" + Student_id + "','" + BirthDate + "','" + EmailAddress + "','" + Password + "','" + Phone_No + "','"+ Year +"')"))
        {
            currentID = query.lastInsertId().toString();
            qDebug() << "Insert success.";
            res = "Insert success.";
        }
        else
        {
            qDebug() << query.lastError().text();
            res = "Failed insertion of data.";
        }

        QString State = "Active";
        QSqlQuery qry;
        if(qry.exec("INSERT INTO status (Student_ID, State) VALUES " "('"+ Student_id +"', '"+ State +"')"))
        {
            qDebug()<<"Inserted status.";

        }
    }
    catch(const char *d)
    {
        return d;
    }
    return res;
}

QString Database::insertLecturer(Lecturer l)
{
    QString FirstName = l.getFirstName();
        QString LastName = l.getLastName();
        QString Gender = l.getGender();
        QString Lecturer_Id = l.getID();
        QString BirthDate = l.getBirthDate();
        QString EmailAddress = l.getEmailAddress();
        QString Password = l.getPassword();
        QString Phone_No = l.getPhoneNo();
        QString res;

        try{
            if(FirstName.isEmpty() || LastName.isEmpty() || Gender.isEmpty() || Lecturer_Id.isEmpty() || BirthDate.isEmpty() || EmailAddress.isEmpty() || Password.isEmpty()|| Phone_No.isEmpty())
            {

                throw "A field is empty, Please fill in all areas";
            }
            qDebug() << "INSERT INTO lecturer (FirstName, LastName, Gender, Lecturer_Id, BirthDate, EmailAddress, Password, Phone_No) VALUES "
                        "('" + FirstName + "','" + LastName + "','" + Gender + "','" + Lecturer_Id + "','" + BirthDate + "','" + EmailAddress + "','" + Password + "','" + Phone_No + "')";
            QSqlQuery query;
            if (query.exec("INSERT INTO lecturer (FirstName, LastName, Gender, Lecturer_Id, BirthDate, EmailAddress, Password, Phone_No) VALUES "
                           "('" + FirstName + "','" + LastName + "','" + Gender + "','" + Lecturer_Id + "','" + BirthDate + "','" + EmailAddress + "','" + Password + "','" + Phone_No + "')"))
            {
                currentID = query.lastInsertId().toString();
                res="Insert Success";
                qDebug() << "Insert success.";
            }
            else
            {
                res ="Failed insertion of data.";
                qDebug() << query.lastError().text();
            }

            QString State = "Active";
            QSqlQuery qry;
            if(qry.exec("INSERT INTO lecturerstatus (Lecturer_Id, State) VALUES " "('"+ Lecturer_Id +"', '"+ State +"')"))
            {
                qDebug()<<currentID;
            }
        }
        catch(const char *d)
        {
            return d;
        }

        return res;
}

QString Database::insertCourse(Course c)
{
    QString Course_Code = c.getcourseId();
        QString Course_Name = c.getcourseName();
        QString Description = c.getcourseDescrip();
        QString Credits = c.getnoOfCredits();
        QString res;
        try
        {
            if(Course_Code.isEmpty() || Course_Name.isEmpty() || Description.isEmpty() || Credits.isEmpty())
            {
                throw "A field is empty, Please fill in all the areas required";
            }
            try
            {
                if(Credits >= 1 && Credits<=3)
                {
                    ;
                }
                else
                {
                    throw "Course credits must range between 1 and 3";
                }
            }
            catch(const char *c)
            {
                return c;
            }

            qDebug() << "INSERT INTO Course (Course_Code, Course_Name, Credits, Description) "
                        "VALUES ('"+ Course_Code +"', '"+ Course_Name +"', '"+ Credits +"', '"+ Description +"')";
            QSqlQuery query;
            if(query.exec("INSERT INTO Course (Course_Code, Course_Name, Credits, Description) "
                          "VALUES ('"+ Course_Code +"', '"+ Course_Name +"', '"+ Credits +"', '"+ Description +"')"))
            {
                currentID = query.lastInsertId().toInt();
                qDebug() << "Insert success";
                res="All clear";
            }
            else
            {
                qDebug() << "failed to connect to database";
                res="Failed insertion";
            }
        }
        catch(const char *c)
        {
            return c;
        }
        return res;
}

QString Database::insertSequence(Sequence d)
{
    QString Syllabus_Id= d.getsyllabusId();
        QString Program= d.getProgram();
        QString Program_Year= d.getprogramYear();
        QString Semester= d.getSemester();
        QString Course_Id= d.getcourseId();
        QString s;

        try
        {
            if(Syllabus_Id.isEmpty() || Program.isEmpty() || Program_Year.isEmpty() || Semester.isEmpty() || Course_Id.isEmpty())
            {
                throw "A field is empty. Fill in all areas.";
            }

            qDebug() << "Creating Course Sequence(SyllabusId, Program, Program Year, Semester, Course) "
                        "WITH VALUES ('"+ Syllabus_Id +"', '"+ Program +"', '"+ Program_Year +"', '"+ Semester +"', '"+ Course_Id +"')";
            QSqlQuery query;

            qDebug()<<"SELECT Program_Id FROM program WHERE Program_Code = '"+ Program +"' ";
            if(query.exec("SELECT Program_Id FROM program WHERE Program_Code = '"+ Program +"' "))
            {
                query.first();
                Program =query.value(0).toString();
                qDebug()<<Program;
            }

            qDebug()<<"SELECT Program_Year_Id FROM program_year WHERE Year = '"+ Program_Year +"'";
            if(query.exec("SELECT Program_Year_Id FROM program_year WHERE Year = '"+ Program_Year +"' "))
            {
                query.first();
                Program_Year=query.value(0).toString();
                qDebug()<<Program_Year;
            }

            qDebug()<<"SELECT Course_ID FROM course WHERE Course_Code = '"+ Course_Id +"'";
            if(query.exec("SELECT Course_ID FROM course WHERE Course_Code = '"+ Course_Id +"' "))
            {
                query.first();
                Course_Id=query.value(0).toString();
                qDebug()<<Course_Id;
            }

            qDebug() << "INSERT INTO syllabus (Syllabus_Id, Program, Program_Year, Semester, Course_Id) "
                        "VALUES ('"+ Syllabus_Id +"', '"+ Program +"', '"+ Program_Year +"', '"+ Semester +"', '"+ Course_Id +"')";

            if(query.exec("INSERT INTO syllabus (Syllabus_Id, Program, Program_Year, Semester, Course_Id) "
                          "VALUES ('"+ Syllabus_Id +"','"+ Program +"','"+ Program_Year +"','"+ Semester +"','"+ Course_Id +"')" ))
            {
                currentID = query.lastInsertId().toInt();
                qDebug()<<"Insert success";
                s="Insert Sucess";
            }
            else
            {
                qDebug()<<"Insert failed!! Denver";
            }

        }
        catch(const char *d)
        {
            return d;
        }
        return s;
}

void Database::connect()
{
    try{
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("");
        db.setDatabaseName("final_project");
        connected = db.open();
        if(connected)
        {
            throw 1;
        }
        else{
            throw "bad Database Connection";
        }
    }
    catch(const int d)
    {
        qDebug() << "connected to database.";
    }
    catch(const char * str)
    {
        qDebug() << "Failed to connect to database."<<str;
    }
}

void Database::disconnectDB() //function to disconnect database
{
    db.close(); //close database connection
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection); //removes the database
    return;
}

void Database::findStudent(QString id)
{
    //    Searchdialog sd;
    qDebug() << "SEARCHING STUDENT (ID) IS: "
                    "('" + id + "')";
        QString id1, fn, ln,ad, pn, g, bd, pswd;

        QSqlQuery query;
        QString sql= "SELECT Student_Id, FirstName, LastName, EmailAddress, Phone_No, Gender, "
                     "BirthDate, Password FROM student WHERE Student_Id = "+ id +" ";
        query.prepare(sql);
        if(query.exec(sql))
        {
            qDebug()<<"Record Found!";
            query.first();
            id1=query.value(0).toString();
            fn=query.value(1).toString();
            ln=query.value(2).toString();
            ad=query.value(3).toString();
            pn=query.value(4).toString();
            g=query.value(5).toString();
            bd=query.value(6).toString();
            pswd=query.value(7).toString();

            qDebug()<<id1<<fn<<ln<<ad<<pn<<g<<bd<<pswd;
        }
        else if(!query.exec())
        {
            qDebug()<<"yuh code nuh work bass";
        }

        if(!id.isEmpty())
        {
            QMessageBox msg;
            msg.setWindowTitle("Results:");
            msg.setText("Id: " + id1 + "\nFirst Name: " + fn + "\nLast Name: "
                        + ln + "\nEmail: " + ad + "\nContact: " + pn +
                        "\nGender: " + g + "\nBirth Date: " + bd +
                        "\nPassword: " + pswd);
            msg.exec();
        }
}


QString Database::resetUserPwd( Reset  r)
{
    QString UserId = r.getuserId();
    QString Password = r.getnewPwd();
    QString UserType = r.getType();
    QString Student_id;
    QString Lecturer_Id;
    QString res;

    QSqlQuery query;

    try{
        if( UserId.isEmpty() || Password.isEmpty() || UserType.isEmpty() )
        {
            throw  "A field is empty, please fill in all areas";
        }
        if(UserType == "student")
        {
            Student_id = UserId;

            query.prepare("UPDATE student SET Password='"+Password+"' WHERE Student_id='"+Student_id+"'");

            if(query.exec())
            {
                res = "Update Success";
                qDebug() << "Update success.";
            }
            else
            {
                qDebug() << "Update failed.";
            }
        }
        else if(UserType == "lecturer")
        {
            Lecturer_Id = UserId;

            query.prepare("UPDATE lecturer SET Password='"+Password+"' WHERE Lecturer_Id='"+Lecturer_Id+"'");

            if(query.exec())
            {
                res = "Update Success";
                qDebug() << "Update success.";
            }
            else
            {
                qDebug() << "Update failed.";
            }
        }
    }
    catch(const char *d)
    {
        return d;
    }
    return res;
}
QString Database::suspendAccount(Suspend s)
{
    QString UserId = s.getuserId();
    QString State = s.getuserStatus();
    QString UserType = s.getType();
    QString Student_id;
    QString Lecturer_Id;
    QString res;
    try{
        if( UserId.isEmpty() || State.isEmpty() || UserType.isEmpty() )
        {
            throw  "A field is empty, please fill in all areas";
        }

        QSqlQuery query;

        if(UserType == "student")
        {
            Student_id = UserId;
            query.prepare("UPDATE status SET State='"+State+"' WHERE Student_id='"+Student_id+"'");
            if(query.exec())
            {
                res = "Update Success";
                qDebug() << "Update success.";
            }
            else
            {
                qDebug() << "Update failed.";
            }
        }
        else if(UserType == "lecturer")
        {
            Lecturer_Id = UserId;

            query.prepare("UPDATE lecturerstatus SET State='"+State+"' WHERE Lecturer_Id='"+Lecturer_Id+"'");
            if(query.exec())
            {
                res = "Update Success";
                qDebug() << "Update success.";
            }
            else
            {
                qDebug() << "Update failed.";
            }
        }
    }
    catch(const char *d)
    {
        return d;
    }
    return res;
}

QString Database::verifyLogin(QString user, QString pswd, QString type)
{
    try
    {
        if(user.isEmpty() || pswd.isEmpty() || type.isEmpty())
        {
            throw "A field is empty. Fill in all areas.";
        }

    }
    catch(const char *d)
    {
        return d;
    }

    QSqlQuery query;
    int count=0;
    QString q;
    LoginScreen login;
    StudentScreen s;

    QSqlQuery statquery;

    try {
        if(type=="student")
        {
            if(query.exec("SELECT * FROM student WHERE Student_Id= '"+ user +"' AND Password= '"+ pswd +"' "))
            {
                while(query.next())
                {
                    count++;
                }
                if(count < 1)
                {
                    throw "Incorrect credentials";
                }
                else if(count == 1)
                {
                    QString stsql= "SELECT State FROM status WHERE Student_Id = "+ user +" ";
                    statquery.prepare(stsql);
                    if(statquery.exec(stsql))
                    {
                        qDebug()<<"Status Found!";
                        statquery.first();
                        status=statquery.value(0).toString();
                        qDebug()<<status;
                        if (status == "Active")
                        {
                            q= "student correct";
                        }
                        else if(status == "Inactive")
                        {
                            q = "student account suspended";
                        }
                    }
                    else if(!statquery.exec())
                    {
                        qDebug()<<"Status not found!";
                    }

                }
            }
        }

        if(type=="lecturer")
        {
            if(query.exec("SELECT * FROM lecturer WHERE Lecturer_Id= '"+ user +"' AND Password= '"+ pswd +"' "))
            {
                while(query.next())
                {
                    count++;
                }
                if(count < 1)
                {
                    throw "Incorrect credentials";
                }
                else if(count == 1)
                {
                    QString stsql= "SELECT State FROM lecturerstatus WHERE Lecturer_Id = '"+ user +"' ";
                    statquery.prepare(stsql);
                    if(statquery.exec(stsql))
                    {
                        qDebug()<<"Status Found!";
                        statquery.first();
                        status=statquery.value(0).toString();
                        qDebug()<<status;
                        if (status == "Active")
                        {
                            q= "lecturer correct";
                        }
                        else if(status == "Inactive")
                        {
                            q = "lecturer account suspended";
                        }
                    }
                    else if(!statquery.exec())
                    {
                        qDebug()<<"Status not found!";
                    }
                }
            }
        }

        if(type=="admin")
        {
            if(query.exec("SELECT * FROM admin WHERE Username= '"+ user +"' AND Password= '"+ pswd +"' "))
            {
                while(query.next())
                {
                    count++;
                }
                if(count < 1)
                {
                    throw "Incorrect credentials";
                }
                else if(count == 1)
                {
                    q = "admin correct";
                }
            }
        }
    }
    catch(const char *d)
    {
        return d;
    }

    return q;
}

QString Database::insertRating(Rating r)
{
    QString Difficulty_Level = r.getDifficulty();
    QString Usefulness = r.getUsefulness();
    QString Comments = r.getComment();
    QString Course_Id = r.getCourse();
    QString Course_Type = r.getCourseType();
    QString School_Year_ID = r.getYear();
    QString Semester_Id = r.getSemester();
    QString Lecturer_Id = r.getLecturer();
    QString res;
    QSqlQuery query;

    try{
        if(Difficulty_Level.isEmpty() || Usefulness.isEmpty() || Comments.isEmpty() || Course_Id.isEmpty() || Course_Type.isEmpty() || School_Year_ID.isEmpty() || Semester_Id.isEmpty() || Lecturer_Id.isEmpty())
        {
            throw "A field is empty!! Please fill in all areas";
        }

        qDebug()<<"SELECT Course_ID FROM course WHERE Course_Code = '"+ Course_Id +"'";
        if(query.exec("SELECT Course_ID FROM course WHERE Course_Code = '"+ Course_Id +"' "))
        {
            query.first();
            Course_Id=query.value(0).toString();
            qDebug()<<Course_Id;
        }

        qDebug()<<"SELECT ID FROM school_year WHERE Year = '"+ School_Year_ID +"'";
        if(query.exec("SELECT ID FROM school_year WHERE Year = '"+ School_Year_ID +"' "))
        {
            query.first();
            School_Year_ID=query.value(0).toString();
            qDebug()<<School_Year_ID;
        }

        qDebug()<<"SELECT Id FROM semester WHERE Semster = '"+ Semester_Id +"'";
        if(query.exec("SELECT Id FROM semester WHERE Semester = '"+ Semester_Id +"' "))
        {
            query.first();
            Semester_Id=query.value(0).toString();
            qDebug()<<Semester_Id;
        }

        qDebug() << "INSERT INTO rating (Difficulty_Level, Usefulness, Comments, Course_Id, Course_Type, School_Year_ID, Semester_Id, Lecturer_Id) VALUES "
                    "('" + Difficulty_Level + "','" + Usefulness + "','" + Comments + "','" + Course_Id + "','" + Course_Type + "','" + School_Year_ID + "','" + Semester_Id + "','" + Lecturer_Id + "')";

        if (query.exec("INSERT INTO rating (Difficulty_Level, Usefulness, Comments, Course_Id, Course_Type, School_Year_ID, Semester_Id, Lecturer_Id) VALUES "
                       "('" + Difficulty_Level + "','" + Usefulness + "','" + Comments + "','" + Course_Id + "','" + Course_Type + "','" + School_Year_ID + "','" + Semester_Id + "','" + Lecturer_Id + "')"))
        {
            currentID = query.lastInsertId().toString();
            qDebug() << "Insert success.";
            res = "Insert success.";
        }
        else
        {
            qDebug() << query.lastError().text();
            res = "Failed insertion of data.";
        }

    }
    catch(const char *d)
    {
        return d;
    }
    return res;
}

QStringList Database::totalGenders()
{
    QStringList totalAmountGender;
    QSqlQuery *query1 = new QSqlQuery;
    query1->prepare("SELECT COUNT(Gender) FROM 'student' WHERE Gender = male");
    totalAmountGender.append(query1->value(0).toString());
    delete query1;


    QSqlQuery * query2 = new QSqlQuery;
    query2->prepare("SELECT COUNT(Gender) FROM 'student' WHERE Gender = female");
    totalAmountGender.append(query2->value(0).toString());
    delete query2;

    return totalAmountGender;

}

QString Database::insertGrade(Grade g)
{
    QString Grade = g.getGrade();
    QString Student_ID = g.getStudentID();
    QString School_Year_ID = g.getYear();
    QString Course_ID = g.getCourse();
    QSqlQuery query;
    QString res;

    try{
        if(Grade.isEmpty() || Student_ID.isEmpty() || School_Year_ID.isEmpty() || Course_ID.isEmpty())
        {
            throw "A field is empty!! Please fill in all areas";
        }

        qDebug()<<"SELECT Course_ID FROM course WHERE Course_Code = '"+ Course_ID +"'";
        if(query.exec("SELECT Course_ID FROM course WHERE Course_Code = '"+ Course_ID +"' "))
        {
            query.first();
            Course_ID=query.value(0).toString();
            qDebug()<<Course_ID;
        }

        qDebug()<<"SELECT ID FROM school_year WHERE Year = '"+ School_Year_ID +"'";
        if(query.exec("SELECT ID FROM school_year WHERE Year = '"+ School_Year_ID +"' "))
        {
            query.first();
            School_Year_ID=query.value(0).toString();
            qDebug()<<School_Year_ID;
        }

        qDebug() << "INSERT INTO grades (Grade, Student_ID, School_Year_ID, Course_ID) VALUES "
                "('" + Grade + "','" + Student_ID + "','" + School_Year_ID + "','" + Course_ID + "')";

        if (query.exec("INSERT INTO grades (Grade, Student_ID, School_Year_ID, Course_ID) VALUES "
                       "('" + Grade + "','" + Student_ID + "','" + School_Year_ID + "','" + Course_ID + "')"))
        {
            currentID = query.lastInsertId().toString();
            qDebug() << "Insert success.";
            res = "Insert success.";
        }
        else
        {
            qDebug() << query.lastError().text();
            res = "Failed insertion of data.";
        }

    }
    catch(const char *d)
    {
        return d;
    }
    return res;
}
