# CLIENT
TEMPLATE = app
OBJECTS_DIR = obj

INCLUDEPATH += /usr/local/include/ ../common/ ./engine ./gameplay


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
    engine/state/State.cpp \
    engine/state/AbstractStateFactory.cpp \
    engine/Context.cpp \
    engine/Application.cpp \
    engine/map.cpp \
    gameplay/MyStateFactory.cpp \
    engine/Camera.cpp \
    entity/EntityManager.cpp \
    entity/Unit.cpp \
    engine/network/NetInterface.cpp \
    entity/MovableEntity.cpp \
    engine/CordinatesHelper.cpp \
    gameplay/game/GameState.cpp \
    gameplay/game/views/GameView.cpp \
    gameplay/game/models/GameModel.cpp \
    gameplay/game/controllers/GameController.cpp \
    engine/state/AbstractStateView.cpp \
    engine/state/AbstractStateController.cpp \
    engine/state/AbstractStateModel.cpp \
    engine/state/debug/DebugState.cpp \
    engine/state/debug/DebugView.cpp \
    engine/state/debug/DebugController.cpp \
    engine/helpers/ViewHelper.cpp \
    engine/helpers/ControllerHelper.cpp \
    engine/helpers/ModelHelper.cpp \
    engine/state/StateStackManager.cpp \
    gameplay/pause/PauseState.cpp \
    gameplay/pause/views/PauseView.cpp \
    gameplay/pause/models/PauseModel.cpp \
    gameplay/pause/controllers/PauseController.cpp

HEADERS += \
    engine/TextureHolder.hpp \
    engine/Textures.hpp \
    engine/SoundHolder.hpp \
    engine/Sounds.hpp \
    engine/state/States.hpp \
    engine/state/State.hpp \
    gameplay/TitleState.hpp \
    engine/state/AbstractStateFactory.hpp \
    engine/Context.hpp \
    engine/Application.hpp \
    engine/map.hpp \
    engine/state/DebugState.hpp \
    gameplay/MyStates.hpp \
    gameplay/MyStateFactory.hpp \
    engine/Camera.hpp \
    entity/EntityManager.hpp \
    entity/Entity.hpp \
    entity/Unit.hpp \
    engine/network/NetInterface.hpp \
    Log.hpp \
    entity/MovableEntity.hpp \
    engine/CordinatesHelper.hpp \
    gameplay/game/GameState.hpp \
    gameplay/game/views/GameView.hpp \
    gameplay/game/models/GameModel.hpp \
    gameplay/game/controllers/GameController.hpp \
    engine/Engine.hpp \
    engine/state/AbstractStateView.hpp \
    engine/state/AbstractStateController.hpp \
    engine/state/AbstractStateModel.hpp \
    engine/state/debug/DebugState.hpp \
    engine/state/DebugController.hpp \
    engine/state/debug/DebugController.hpp \
    engine/helpers/ViewHelper.hpp \
    engine/helpers/ControllerHelper.hpp \
    engine/helpers/ModelHelper.hpp \
    engine/state/StateStackManager.hpp \
    gameplay/Gameplay.hpp \
    gameplay/pause/PauseState.hpp \
    gameplay/pause/views/PauseView.hpp \
    gameplay/pause/models/PauseModel.hpp \
    gameplay/pause/controllers/PauseController.hpp

