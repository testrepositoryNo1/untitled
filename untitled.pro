TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14
CONFIG += -g


LIBS += -L/path/boost/lib/ -lboost_thread -lboost_system -lboost_chrono -lboost_filesystem
LIBS += -L/usr/lib/libcryptopp.a -lcryptopp

#LIBS += -L /usr/include/python2.7/ -lpython2.7 #--- Python doesn't work ---#


SOURCES += main.cpp
QMAKE_CXXFLAGS += -std=c++11


HEADERS += \
    stdfx.h \
    main.h
