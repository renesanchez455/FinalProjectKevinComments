#-------------------------------------------------
#
# Project created by QtCreator 2021-04-18T23:04:00
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Final_Project1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    admin.cpp \
    grade.cpp \
    gradedialog.cpp \
    lecturerscreen.cpp \
        main.cpp \
    lecturerdialog.cpp \
    course.cpp \
    Student.cpp \
    rating.cpp \
    ratingdialog.cpp \
    reset.cpp \
    resetdialog.cpp \
    sequence.cpp \
    studentscreen.cpp \
    suspend.cpp \
    suspenddialog.cpp \
    transfer.cpp \
    transferdialog.cpp \
    user.cpp \
    lecturer.cpp \
    searchdialog.cpp \
    database.cpp \
    coursedialog.cpp \
    studentdialog.cpp \
    loginscreen.cpp \
    sequencedialog.cpp

HEADERS += \
    admin.h \
    grade.h \
    gradedialog.h \
    lecturerdialog.h \
    course.h \
    Student.h \
    lecturerscreen.h \
    rating.h \
    ratingdialog.h \
    reset.h \
    resetdialog.h \
    sequence.h \
    studentscreen.h \
    suspend.h \
    suspenddialog.h \
    transfer.h \
    transferdialog.h \
    user.h \
    lecturer.h \
    searchdialog.h \
    database.h \
    coursedialog.h \
    studentdialog.h \
    loginscreen.h \
    sequencedialog.h

FORMS += \
    admin.ui \
    gradedialog.ui \
    lecturerdialog.ui \
    lecturerscreen.ui \
    ratingdialog.ui \
    resetdialog.ui \
    searchdialog.ui \
    coursedialog.ui \
    studentdialog.ui \
    loginscreen.ui \
    sequencedialog.ui \
    studentscreen.ui \
    suspenddialog.ui \
    transferdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons/icons.qrc \
    Images.qrc \
    translations.qrc \
    translations.qrc
TRANSLATIONS += trans_es.ts
