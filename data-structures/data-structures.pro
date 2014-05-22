TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lgtest -lgtest_main -lpthread

SOURCES += main.cpp \
    hashtable.cpp

HEADERS += \
    hashtable.h

