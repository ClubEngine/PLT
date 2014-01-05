# PLT
TEMPLATE = app

#LIBS += -L/usr/local/lib/SFML-2.1/lib/
INCLUDEPATH=/usr/local/include/
#INCLUDEPATH += /usr/local/lib/SFML-2.1/include/

# debug
LIBS += -L/usr/local/lib/ -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-system-d
# release
#LIBS += -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

SOURCES += main.cpp \
    TextureHolder.cpp

HEADERS += \
    TextureHolder.hpp \
    Textures.hpp

