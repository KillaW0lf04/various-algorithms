TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += quicksort.h \
           heapsort.h \
           mergesort.h \
    insertionsort.h \
    bubblesort.h

SOURCES += main.cpp \
           quicksort.cpp \
           heapsort.cpp \
           mergesort.cpp \
    insertionsort.cpp \
    bubblesort.cpp

