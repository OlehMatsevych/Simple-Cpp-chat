#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>

class Socket;

class Server: public QTcpServer
{
public:
    Server(QObject *parent =nullptr);
    bool startServer(quint16 PORT);
protected:
    void incomingConnection(qintptr handle);
private:
    QList<Socket*> sockets;
};

#endif // SERVER_H
