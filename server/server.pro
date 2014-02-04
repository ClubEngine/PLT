TEMPLATE = app
OBJECTS_DIR = obj

INCLUDEPATH += /usr/local/include/ ../common/

# all
LIBS += -L../common/ \
    -lcommon
# debug
LIBS += -L/usr/local/lib/ -lsfml-network-d -lsfml-system-d
# release
#LIBS += -L/usr/local/lib/ -lsfml-network -lsfml-system

SOURCES += main.cpp \
    network/ReusableTcpListener.cpp

HEADERS += \
    network/ReusableTcpListener.hpp

