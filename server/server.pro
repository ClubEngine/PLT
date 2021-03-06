TEMPLATE = app
OBJECTS_DIR = obj

INCLUDEPATH += /usr/local/include/ ../common/


# debug
CONFIG(debug) {
    LIBS += -L/usr/local/lib/ \
        -lsfml-graphics-d \
        -lsfml-window-d \
        -lsfml-audio-d \
        -lsfml-network-d \
        -lsfml-system-d \
        -L../common/ \
        -lcommon-d
}

# release
CONFIG(release) {
    LIBS += -L/usr/local/lib/ \
        -lsfml-graphics \
        -lsfml-window \
        -lsfml-audio \
        -lsfml-system \
        -lsfml-network \
        -L../common/ \
        -lcommon
}

SOURCES += main.cpp \
    network/ReusableTcpListener.cpp \
    client.cpp \
    server.cpp

HEADERS += \
    network/ReusableTcpListener.hpp \
    client.hpp \
    server.hpp

