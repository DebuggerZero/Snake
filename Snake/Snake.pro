QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Game/Archive/archive.cpp \
    Game/Area.cpp \
    Game/Food.cpp \
    Game/GameView/gmainwidget.cpp \
    Game/GameView/gstartwidght.cpp \
    Game/Snake.cpp \
    Game/Utility/utility.cpp \
    main.cpp \

HEADERS += \
    Game/Archive/archive.h \
    Game/Area.h \
    Game/Food.h \
    Game/GameView/gmainwidget.h \
    Game/GameView/gstartwidght.h \
    Game/Snake.h \
    Game/Utility/utility.h

FORMS += \
    Game/GameView/gmainwidget.ui \
    Game/GameView/gstartwidght.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
