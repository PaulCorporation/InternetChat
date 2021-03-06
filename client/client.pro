######################################################################
# Automatically generated by qmake (3.1) Tue Jun 2 13:45:02 2020
######################################################################

TEMPLATE = app
TARGET = client
INCLUDEPATH += .
CONFIG += c++14
QT += gui core widgets network
# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += app.h \
           interfaces/account/account_creation_page.h \
           interfaces/chat/chat.h \
           interfaces/connexion/connexion_page.h \
    packet.h
FORMS += interfaces/account/create_account.ui \
         interfaces/chat/chat.ui \
         interfaces/connexion/connexion.ui
SOURCES += app.cpp \
           main.cpp \
           interfaces/account/account_creation_page.cpp \
           interfaces/chat/chat.cpp \
           interfaces/connexion/connexion_page.cpp \
    packet.cpp
