#include "socket.h"

Socket::Socket(qintptr handle, QObject *parent)
    :QTcpSocket(parent)
{
    setSocketDescriptor(handle);

    connect(this, &Socket::readyRead, [&](){
        emit DoReadyRead(this);

    });
    connect(this, &Socket::stateChanged, [&](int S)
    {
        emit DoStateChanged(this, S);

    });
}
