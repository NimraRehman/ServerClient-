#ifndef CLIENTSIDE_H
#define CLIENTSIDE_H

#include <QObject>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include "QtNetwork"
#include <QNetworkInterface>

class ClientSide : public QObject
{
    Q_OBJECT
public:
    explicit ClientSide(QObject *parent = 0);
    void start(QString address, quint16 port);

signals:

public slots:
    //void connectedToServer();
  //void writeToServer();
   void closedByServer();
    //void startTransfer ();

private:
    QTcpSocket *cSocket;
    QString cString;
QTcpSocket *clientside;
};

#endif // CLIENTSIDE_H
