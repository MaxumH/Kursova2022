CONFIG(release, debug|release) {
 QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt $$OUT_PWD/release
}
MOC_DIR = moc
RCC_DIR = rcc
UI_DIR = ui
unix:OBJECTS_DIR = unix
win32:OBJECTS_DIR = win32
macx:OBJECTS_DIR = mac (edited)


QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbmanager.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    sqlitedbmanager.cpp

HEADERS += \
    dbmanager.h \
    form.h \
    mainwindow.h \
    sqlitedbmanager.h

FORMS += \
    form.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
