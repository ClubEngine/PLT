#-------------------------------------------------
#
# Project created by QtCreator 2014-02-04T21:52:39
#
#-------------------------------------------------

QT       -= core gui


TEMPLATE = lib
CONFIG += staticlib # debug_and_release



debug {
    TARGET = common-d
} else:release {
    TARGET = common
}


SOURCES += commands/gameplay/CommandMove.cpp \
    commands/core/Command.cpp \
    entity/Entity.cpp \
    commands/gameplay/CommandBuild.cpp

HEADERS += commands/gameplay/CommandMove.hpp \
    commands/gameplay/CommandsType.hpp \
    commands/core/Command.hpp \
    entity/Entity.hpp \
    commands/gameplay/CommandBuild.hpp \
    network/Network.hpp \
    Common.hpp

