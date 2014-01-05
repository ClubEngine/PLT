# PLT
TEMPLATE = app

#LIBS += -L/home/juleffel/Documents/glew/lib -L/usr/local/sfml/lib -L/usr/lib -L/lib -L/usr/lib/x86_64-linux-gnu
#LIBS += -L/usr/local/lib/SFML-2.1/lib/
INCLUDEPATH  += /usr/local/include/
#INCLUDEPATH += /usr/local/lib/SFML-2.1/include/

# debug
#LIBS += -L/usr/local/lib/ -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-system-d
# release
LIBS += -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

SOURCES += \
    main.cpp \
    core/Game.cpp \
    core/TextureHolder.cpp \
    core/SoundHolder.cpp

HEADERS += \
    core/Game.hpp \
    core/TextureHolder.hpp \
    core/Textures.hpp \
    core/SoundHolder.hpp \
    core/Sounds.hpp
