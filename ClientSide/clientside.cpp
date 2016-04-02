#include "clientside.h"
#include "QHostAddress"

ClientSide::ClientSide(QObject *parent) :
    QObject(parent)
{
    cSocket = new QTcpSocket(this);
    cSocket->connectToHost(QHostAddress::LocalHost,2222);
    if (cSocket->waitForConnected(3000))
        qDebug() << "Network set up !";
    else
    {
        qDebug() << "No network setup";
    }

//    connect(cSocket, SIGNAL(newConnection()), this, SLOT(connectedToserver()));
}

//void ClientSide::connectedToServer()
//{
//    qDebug() << "connectedToServer compiling";
//       connect(clientside, SIGNAL(writeData()), this, SLOT(startTransfer()));
//}

//void ClientSide::start(QString address, quint16 port)
//{
//    QHostAddress addr(address);
//    clientside->connectToHost(addr, port);

//}
//void ClientSide :: startTransfer()
//{
//    clientside->write ("Share keys", 20);
//}
void ClientSide::closedByServer()
{

}
