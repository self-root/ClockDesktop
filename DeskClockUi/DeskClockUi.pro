QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    appselection.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    shortcutbutton.cpp \
    shortcutdialog.cpp \
    tododialog.cpp \
    todolistview.cpp

HEADERS += \
    about.h \
    appselection.h \
    dialog.h \
    mainwindow.h \
    shortcutbutton.h \
    shortcutdialog.h \
    tododialog.h \
    todolistview.h

FORMS += \
    about.ui \
    appselection.ui \
    mainwindow.ui \
    shortcutdialog.ui \
    tododialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DeskClockCore/release/ -lDeskClockCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DeskClockCore/debug/ -lDeskClockCore
else:unix:!macx: LIBS += -L$$OUT_PWD/../DeskClockCore/ -lDeskClockCore

INCLUDEPATH += $$PWD/../DeskClockCore
DEPENDPATH += $$PWD/../DeskClockCore

RESOURCES += \
    assets.qrc

RC_ICONS = assets/icons/shortcut.ico
