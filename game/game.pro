TEMPLATE = app
TARGET = penjinoid
DESTDIR = ../target
QT -= core gui

INCLUDEPATH += ../penjin
LIBS += -L../penjin -lpenjin
DEFINES += PENJIN_SDL PLATFORM_PC _LINUX

HEADERS = \
  ball.h \
  brick.h \
  gamestate.h \
  paddle.h \
  penjinoid.h

SOURCES = \
  ball.cpp \
  brick.cpp \
  gamestate.cpp \
  main.cpp \
  paddle.cpp \
  penjinoid.cpp

OTHER_FILES = \
  ../target/config/settings.ini
