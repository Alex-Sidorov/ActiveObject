TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    abstracttask.cpp \
    scheduler.cpp \
    proxyactiveobject.cpp

HEADERS += \
    abstracttask.h \
    scheduler.h \
    proxyactiveobject.h
