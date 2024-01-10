TEMPLATE	= app
CONFIG		+= qt warn_on
HEADERS		=
SOURCES		= main.cpp
TARGET		= main
QTDIR_build:REQUIRES="contains(QT_CONFIG, small-config)"

QT += widgets

# install
target.path = ~/Schreibtisch/Projekt
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS t1.pro
sources.path = ~/Schreibtisch/Projekt
INSTALLS += target sources
