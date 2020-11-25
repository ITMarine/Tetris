QT += core gui

TARGET = G
TEMPLATE = app
SOURCES += main.cpp \
    functions.cpp

CONFIG += link_pkgconfig
PKGCONFIG += sfml-all

HEADERS += \
    functions.h \
    map.h
