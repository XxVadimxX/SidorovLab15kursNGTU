TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        procapp.cpp

HEADERS += \
    inputpacket.h \
    outpacket.h \
    procapp.h
