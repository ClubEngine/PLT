# PLT
TEMPLATE = app

#LIBS += -L/usr/local/lib/SFML-2.1/lib/

# debug
LIBS += -L/usr/local/lib/ -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-system-d
# release
#LIBS += -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

INCLUDEPATH += /usr/local/lib/SFML-2.1/include/

SOURCES += main.cpp

