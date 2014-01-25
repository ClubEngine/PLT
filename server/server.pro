TEMPLATE = app
#CONFIG += console
#CONFIG -= qt

# debug
LIBS += -L/usr/local/lib/ -lsfml-network-d -lsfml-system-d
# release
#LIBS += -L/usr/local/lib/ -lsfml-network -lsfml-system

SOURCES += main.cpp

