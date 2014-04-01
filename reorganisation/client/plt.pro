# PLT
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
        -lsfml-system-d
    
    LIBS += -L../common/ \
        -lcommon-d
}

# release
CONFIG(release) {
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
    Application.cpp \
    Controller/Controller.cpp \
    View/View.cpp \
    Model/Model.cpp

HEADERS += \
	Application.hpp \
    Application.hpp \
    Controller/Controller.hpp \
    View/View.hpp \
    Model/Model.hpp

