# PLT
TEMPLATE = app
OBJECTS_DIR = obj

INCLUDEPATH += /usr/local/include/ #../common/


# debug
CONFIG(debug) {
    LIBS += -L/usr/local/lib/ \
        -lsfml-graphics-d \
        -lsfml-window-d \
        -lsfml-audio-d \
        -lsfml-network-d \
        -lsfml-system-d
    
#   LIBS += -L../common/ \
#       -lcommon-d
}

# release
CONFIG(release) {
    LIBS += -L/usr/local/lib/ \
        -lsfml-graphics \
        -lsfml-window \
        -lsfml-audio \
        -lsfml-system \
        -lsfml-network

#   LIBS += -L../common/ \
#
}

SOURCES += \
    main.cpp \
    engine/Application.cpp \
    engine/state/State.cpp \
    engine/state/StateFactory.cpp \
    engine/state/StateStack.cpp \
    engine/state/StateStackManager.cpp \
    gameplay/states/RTSStateFactory.cpp \
    gameplay/states/GameState/GameState.cpp \
    gameplay/states/MVC/Controller.cpp \
    gameplay/states/MVC/View.cpp \
    gameplay/states/MVC/Model.cpp \

HEADERS += \
    engine/Application.hpp \
    engine/state/State.hpp \
    engine/state/StateFactory.hpp \
    engine/state/StateStack.hpp \
    engine/state/StateStackManager.hpp \
    gameplay/states/RTSStateFactory.hpp \
    gameplay/states/RTSStatesID.hpp \
    gameplay/states/GameState/GameState.hpp \
    gameplay/states/MVC/Controller.hpp \
    gameplay/states/MVC/View.hpp \
    gameplay/states/MVC/Model.hpp \
    tools/Factory.hpp \

