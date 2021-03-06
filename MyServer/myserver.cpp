#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
    if(!server->listen(QHostAddress::LocalHost, 2222))
    {
        qDebug() << "not started";
    }
    else
    {
        qDebug() << "Server Client network setup";
    }

    connect(server, SIGNAL(newConnection()), this, SLOT(serverConnected()));

}

void MyServer::serverConnected()
{
       servSocket = server->nextPendingConnection();
    if(servSocket->state()== QAbstractSocket::ConnectedState)
    {
        qDebug() << "Connected";
        qDebug() << "Peer address: " << servSocket->peerAddress();
        qDebug() << "Peer port: " << servSocket->peerPort();

    }
    servSocket->write("Hello client\r\n");
    servSocket->flush();
    servSocket->waitForBytesWritten(3000);
    servSocket->close();
}


//create a socket - Get the file descriptor!
//bind to an address -What port am I on?
//listen on a port, and wait for a connection to be established.
//accept the connection from a client.
//send/recv - the same way we read and write for a file.
//shutdown to end read/write.
//close to releases data.



//Note: The returned QTcpSocket object cannot be
//used from another thread. If you want to use
//an incoming connection from another thread,
//you need to override incomingConnection().

