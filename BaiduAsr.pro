#-------------------------------------------------
#
# Project created by QtCreator 2019-08-20T19:14:19
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BaiduAsr
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS _GLIBCXX_USE_CXX11_ABI=0

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += $$PWD/include \
               $$PWD/include/ASR

DEPENDPATH += $$PWD/include \
              $$PWD/include/ASR


unix{
LIBS += -L$$PWD/lib/ -lBDSpeechSDK \
        -L$$PWD/extern/lib/ -lcurl \
        -L$$PWD/extern/lib/ -liconv \
        -L$$PWD/extern/lib/ -lz \
        -L$$PWD/extern/lib/ -lssl \
        -L$$PWD/extern/lib/ -lcrypto \
        -L$$PWD/extern/lib/ -luuid \
        -lrt \
        -ldl \
}

include(./BaiduApi/baiduapi.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
