# PLT
TEMPLATE = app
OBJECTS_DIR = obj

INCLUDEPATH += /usr/local/include/ ../common/


# debug
CONFIG(debug) {
    LIBS += -L/usr/local/lib/ \
        -lsfml-graphics-d \
        -lsfml-window-d \
        -lsfml-audio-d \
        -lsfml-network-d \
        -lsfml-system-d
    
    LIBS += -L../common/ \
        -lcommon-d
}

# release
CONFIG(release) {
    LIBS += -L/usr/local/lib/ \
        -lsfml-graphics \
        -lsfml-window \
        -lsfml-audio \
        -lsfml-system \
        -lsfml-network

    LIBS += -L../common/ \
        -lcommon
}

SOURCES += \
    main.cpp \
    core/TextureHolder.cpp \
    core/SoundHolder.cpp \
    core/state/StateStack.cpp \
    core/state/State.cpp \
    gameplay/TitleState.cpp \
    core/state/AbstractStateFactory.cpp \
    core/Context.cpp \
    gameplay/GameState.cpp \
    core/Application.cpp \
    core/map.cpp \
    core/state/DebugState.cpp \
    gameplay/TestState.cpp \
    gameplay/MyStateFactory.cpp \
    gameplay/PauseState.cpp \
    core/Camera.cpp \
    entity/EntityManager.cpp \
    entity/Unit.cpp \
    core/network/NetInterface.cpp \
    entity/MovableEntity.cpp \
    core/CordinatesHelper.cpp

HEADERS += \
    core/TextureHolder.hpp \
    core/Textures.hpp \
    core/SoundHolder.hpp \
    core/Sounds.hpp \
    core/state/StateStack.hpp \
    core/state/States.hpp \
    core/state/State.hpp \
    gameplay/TitleState.hpp \
    core/state/AbstractStateFactory.hpp \
    core/Context.hpp \
    gameplay/GameState.hpp \
    core/Application.hpp \
    core/map.hpp \
    core/state/DebugState.hpp \
    gameplay/TestState.hpp \
    gameplay/MyStates.hpp \
    gameplay/MyStateFactory.hpp \
    gameplay/PauseState.hpp \
    core/Camera.hpp \
    entity/EntityManager.hpp \
    entity/Entity.hpp \
    entity/Unit.hpp \
    core/network/NetInterface.hpp \
    Log.hpp \
    entity/MovableEntity.hpp \
    core/CordinatesHelper.hpp

