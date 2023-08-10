######################################################################
# Automatically generated by qmake (3.1) Thu Aug 3 10:37:30 2023
######################################################################

TEMPLATE = app
TARGET = ZOO
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += src/Animal.h \
           src/animaltype.h \
           src/Coccodrillo.h \
           src/Container.h \
           src/generate.h \
           src/Giraffa.h \
           src/Leone.h \
           src/Pavone.h \
           src/Struzzo.h \
           src/Tartaruga.h \
           src/clock.h \
           viewer/digitalClock.h \
           viewer/gameWidget.h \
           viewer/mainMenu.h \
           viewer/gameModel.h \
           dataManager/dataManager.h
SOURCES += main.cpp \
           src/Animal.cpp \
           src/animaltype.cpp \
           src/Coccodrillo.cpp \
           src/generate.cpp \
           src/Giraffa.cpp \
           src/Leone.cpp \
           src/Pavone.cpp \
           src/Struzzo.cpp \
           src/Tartaruga.cpp \
           src/clock.cpp \
           viewer/digitalClock.cpp \
           viewer/gameWidget.cpp \
           viewer/mainMenu.cpp \
           viewer/gameModel.cpp \
           dataManager/dataManager.cpp

QT += widgets 
QT += gui
