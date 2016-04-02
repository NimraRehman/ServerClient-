#include <QCoreApplication>
#include "clientside.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ClientSide newClient;

        return a.exec();
}
