QT += core


CONFIG += c++11

TARGET = test

CONFIG += console
CONFIG += c++14
CONFIG -= app_bundle

INCLUDEPATH += $$PWD/

TEMPLATE = app

HEADERS +=  enum_strmap.h \
    moduleobserver.h

SOURCES += $$PWD/test.cpp \
    moduleobserver.cpp

include($$PWD/notifier_include/notifier_include.pri)
