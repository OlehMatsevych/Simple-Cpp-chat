#include "server.h"
#include "socket.h"
#include <QTextStream>
#include <QDebug>

Server::Server(QObject *parent)
    :QTcpServer(parent)
{
}
bool Server::startServer(quint16 PORT)
{

    return listen(QHostAddress::Any, PORT);
}

void Server::incomingConnection(qintptr handle)
{
    qDebug()<<"Client connected(handle = "<<handle<<") ";
    auto socket = new Socket(handle,this);
    sockets<<socket;

    for(auto i: sockets)
    {
        QTextStream T(i);
        T<<" Server: Connected: "<<handle;
        i->flush();
    }
    connect(socket, &Socket::DoReadyRead, [&](Socket*S)
    {
        qDebug()<<"Ready";
        QTextStream T(S);
        auto text = T.readAll();

        for(auto i: sockets)
        {
           QTextStream K(i);
           K<<text;
           i->flush();
        }
    });
    connect(socket, &Socket::DoStateChanged,
            [&](Socket * S, int ST)
    {
        qDebug()<<"State Changed";
        if(ST == QTcpSocket::UnconnectedState )
        {
            qDebug()<<"Incorrect state";
            sockets.removeOne(S);
            for(auto i: sockets)
            {
                QTextStream K(i);
                K<<"Server: client "
                <<S->socketDescriptor()<<"disconnect";
                i->flush();
            }
        }
    });
}
