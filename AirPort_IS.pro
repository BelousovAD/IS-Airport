QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountwindow.cpp \
    addflightdialog.cpp \
    admin.cpp \
    authorisationwindow.cpp \
    book.cpp \
    buyticketdialog.cpp \
    cashier.cpp \
    main.cpp \
    mainwindow.cpp \
    menuadminwindow.cpp \
    menucashierwindow.cpp \
    menuwindow.cpp \
    passenger.cpp \
    registrationwindow.cpp \
    ticketslistwindow.cpp \
    ticketwindow.cpp \
    user.cpp

HEADERS += \
    accountwindow.h \
    addflightdialog.h \
    admin.h \
    authorisationwindow.h \
    book.h \
    buyticketdialog.h \
    cashier.h \
    flight.h \
    mainwindow.h \
    menuadminwindow.h \
    menucashierwindow.h \
    menuwindow.h \
    passenger.h \
    registrationwindow.h \
    ticket.h \
    ticketslistwindow.h \
    ticketwindow.h \
    user.h

FORMS += \
    accountwindow.ui \
    addflightdialog.ui \
    authorisationwindow.ui \
    buyticketdialog.ui \
    mainwindow.ui \
    menuadminwindow.ui \
    menucashierwindow.ui \
    menuwindow.ui \
    registrationwindow.ui \
    ticketslistwindow.ui \
    ticketwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
