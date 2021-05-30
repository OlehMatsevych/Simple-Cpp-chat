QT       += core
QT       += network
QT       -= gui

TARGET = QTcpSocket
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
SOURCES += \
        main.cpp \
        server.cpp \
        socket.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    server.h \
    socket.h
