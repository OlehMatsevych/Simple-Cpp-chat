#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>

class Socket: public QTcpSocket
{
    Q_OBJECT
public:
    Socket(qintptr handle, QObject *parent = nullptr);

signals:
    void DoReadyRead(Socket* );
    void DoStateChanged(Socket*, int);
};

#endif // SOCKET_H
