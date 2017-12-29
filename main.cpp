#include "widget.h"
#include <QApplication>
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include "TcpLayerr.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpLayer connect(4555);
    Widget w(&connect);
    w.show();
    return a.exec();
}
