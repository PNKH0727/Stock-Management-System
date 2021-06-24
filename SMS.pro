QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = Doctor_Appointment_In_QT
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    additems.cpp \
    customer.cpp \
    deleteitems.cpp \
    firstform.cpp \
    main.cpp \
    login.cpp \
    registernew.cpp \
    status.cpp \
    uiform.cpp \
    updateitems.cpp \
    users.cpp

HEADERS += \
    additems.h \
    customer.h \
    deleteitems.h \
    firstform.h \
    login.h \
    registernew.h \
    status.h \
    uiform.h \
    updateitems.h \
    users.h

FORMS += \
    additems.ui \
    customer.ui \
    deleteitems.ui \
    firstform.ui \
    login.ui \
    registernew.ui \
    status.ui \
    uiform.ui \
    updateitems.ui \
    users.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
