TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lgtest -lgtest_main -lpthread

SOURCES += \
    hashtable.cpp \
    hashtable_test.cpp \
    linkedlist.cpp \
    linkedlist_test.cpp

HEADERS += \
    hashtable.h \
    linkedlist.h

