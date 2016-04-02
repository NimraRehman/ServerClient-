#ifndef MYSERVER_H
#define MYSERVER_H
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include <QTcpSocket>
#include <QNetworkSession>
#include <QString>

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0); //creating a new server

public slots:
    void serverConnected();


private slots:

private:
    QTcpServer *server;
    QTcpSocket *servSocket;

};

#endif // MYTCPSOCKET_H

//1. socket() - Create a server
//2. bind() - Name the socket
//3. listen() - Prepare the socket to listen
//4. accept() - Wait for a request to connect, a new client socket is created
//5. read() - Read data sent from the client
//6. write() - Send data back to the client
//7. close() - Close client socket
//8. loopback if not told to exit: close() ----->listen()
//9. close() - Close server socket is exit command given by client
