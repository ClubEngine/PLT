# PLT
TEMPLATE = app

# LIBS += -L/home/juleffel/Documents/glew/lib -L/usr/local/sfml/lib -L/usr/lib -L/lib -L/usr/lib/x86_64-linux-gnu
# LIBS += -L/usr/local/lib/SFML-2.1/lib/
INCLUDEPATH += /usr/local/include/

# INCLUDEPATH += /usr/local/lib/SFML-2.1/include/
# debug
LIBS += -L/usr/local/lib/ \
    -lsfml-graphics-d \
    -lsfml-window-d \
    -lsfml-audio-d \
    -lsfml-network-d \
    -lsfml-system-d

# release
# LIBS += -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

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
    entity/Entity.cpp \
    entity/Unit.cpp \
    core/network/Command.cpp \
    core/network/CommandFactory.cpp \
    core/network/NetInterface.cpp

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
    core/network/Command.hpp \
    core/network/CommandFactory.hpp \
    core/network/NetInterface.hpp

