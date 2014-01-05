# PLT
TEMPLATE = app

#LIBS += -L/home/juleffel/Documents/glew/lib -L/usr/local/sfml/lib -L/usr/lib -L/lib -L/usr/lib/x86_64-linux-gnu

# debug
LIBS += -L/usr/local/lib/ -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-system-d

# release
#LIBS += -L/usr/local/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

INCLUDEPATH += /usr/local/sfml/include/

SOURCES += main.cpp

