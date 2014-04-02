# CLIENT
TEMPLATE = app
OBJECTS_DIR = obj

INCLUDEPATH += /usr/local/include/ ../common/


debug {
    LIBS += -L/usr/local/lib/ \
        -lsfml-graphics-d \
        -lsfml-window-d \
        -lsfml-audio-d \
        -lsfml-network-d \
        -lsfml-system-d
    
    LIBS += -L../common/ \
        -lcommon-d
} else:release {
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
    engine/TextureHolder.cpp \
    engine/SoundHolder.cpp \
    engine/state/StateStack.cpp \
    engine/state/State.cpp \
    gameplay/TitleState.cpp \
    engine/state/AbstractStateFactory.cpp \
    engine/Context.cpp \
    gameplay/GameState.cpp \
    engine/Application.cpp \
    engine/map.cpp \
    engine/state/DebugState.cpp \
    gameplay/TestState.cpp \
    gameplay/MyStateFactory.cpp \
    gameplay/PauseState.cpp \
    engine/Camera.cpp \
    entity/EntityManager.cpp \
    entity/Unit.cpp \
    engine/network/NetInterface.cpp \
    entity/MovableEntity.cpp \
    engine/CordinatesHelper.cpp

HEADERS += \
    engine/TextureHolder.hpp \
    engine/Textures.hpp \
    engine/SoundHolder.hpp \
    engine/Sounds.hpp \
    engine/state/StateStack.hpp \
    engine/state/States.hpp \
    engine/state/State.hpp \
    gameplay/TitleState.hpp \
    engine/state/AbstractStateFactory.hpp \
    engine/Context.hpp \
    gameplay/GameState.hpp \
    engine/Application.hpp \
    engine/map.hpp \
    engine/state/DebugState.hpp \
    gameplay/TestState.hpp \
    gameplay/MyStates.hpp \
    gameplay/MyStateFactory.hpp \
    gameplay/PauseState.hpp \
    engine/Camera.hpp \
    entity/EntityManager.hpp \
    entity/Entity.hpp \
    entity/Unit.hpp \
    engine/network/NetInterface.hpp \
    Log.hpp \
    entity/MovableEntity.hpp \
    engine/CordinatesHelper.hpp

