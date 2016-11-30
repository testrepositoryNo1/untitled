TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14

LIBS += -L/path/boost/lib/ -lboost_thread -lboost_system -lboost_chrono -lboost_filesystem
#LIBS += -L/usr/lib/libcryptopp.a -lcryptopp


SOURCES += main.cpp
QMAKE_CXXFLAGS += -std=c++11


HEADERS += \
    stdfx.h \
    main.h
