#ifndef TCPLAYER_H
#define TCPLAYER_H

#include <QTcpSocket>
#include "ConnectionInterface.h"
#include <QString>
#include <QList>

class TcpLayer : public ConnectionInterface
{
    Q_OBJECT
public:
    explicit TcpLayer(const uint16_t port, std::string ipAddress = "localhost", QObject *parent = 0);
    virtual ~TcpLayer(){
        if(socket->isOpen()) {
            socket->close();
        }
        lst.clear();
        delete socket;
    }
public slots:
    void writeToDeamonMsg(const QString& msg);
private slots:
    void succsesConnectToDeamon();
    void readHandler();
private:
    QTcpSocket* socket;
    QString servAddr;
    const qint16 servPort;
    const uint16_t maxSizeDataBuffer;
    QList<QString> lst;
    const QString protocolVersion;
};

#endif // TCPLAYER_H
