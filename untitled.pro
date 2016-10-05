TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14

SOURCES += main.cpp
QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    stdfx.h \
    main.h
