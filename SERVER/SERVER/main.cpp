#include <QCoreApplication>
#include "server.h"

#define PORT 3000

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server MyServer;
    if(!MyServer.startServer(PORT))
    {
        qDebug()<<"Error: " <<MyServer.errorString();
        return -1;
    }
    qDebug()<<"Server statred ";
    return a.exec();
}
