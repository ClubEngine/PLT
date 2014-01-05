# PLT
TEMPLATE = app

# debug
LIBS += -L/usr/local/lib/ -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-system-d
# release
#LIBS += -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

SOURCES += main.cpp \
    TextureHolder.cpp

HEADERS += \
    TextureHolder.hpp \
    Textures.hpp

