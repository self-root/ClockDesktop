QT -= gui
QT += sql

TEMPLATE = lib
DEFINES += DESKCLOCKCORE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    databasemanager.cpp \
    shortcut.cpp \
    shortcutdao.cpp \
    toDo.cpp \
    tododao.cpp \
    todomodel.cpp

HEADERS += \
    controller.h \
    databasemanager.h \
    deskClockCore_global.h \
    deskclockexception.h \
    shortcut.h \
    shortcutdao.h \
    toDo.h \
    tododao.h \
    todomodel.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
