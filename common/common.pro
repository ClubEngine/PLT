#-------------------------------------------------
#
# Project created by QtCreator 2014-02-04T21:52:39
#
#-------------------------------------------------

QT       -= core gui

TARGET = common
TEMPLATE = lib
CONFIG += staticlib

SOURCES += commands/gameplay/CommandMove.cpp \
    commands/core/Command.cpp \
    entity/Entity.cpp \
    commands/gameplay/CommandBuild.cpp

HEADERS += commands/gameplay/CommandMove.hpp \
    commands/gameplay/CommandsType.hpp \
    commands/core/Command.hpp \
    entity/Entity.hpp \
    commands/gameplay/CommandBuild.hpp
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
