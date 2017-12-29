#include "TcpLayerr.h"
#include <widget.h>

TcpLayer::TcpLayer(uint16_t port, std::string ipAddress, QObject *parent) : ConnectionInterface(parent),
    socket(new QTcpSocket(this)),
    servPort(port),
    maxSizeDataBuffer(256){
    servAddr = ipAddress.c_str();
    dataBuffer = new char(maxSizeDataBuffer);
    QObject::connect(socket,SIGNAL(connected()), this, SLOT(succsesConnectToDeamon()));
    QObject::connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(writeHandler(qint64)));
    QObject::connect(socket, SIGNAL(readyRead()),this, SLOT(readHandler()));
    socket->connectToHost(servAddr,servPort);
}

void TcpLayer::writeToDeamonMsg(const QString &msg){
    socket->write(msg.toUtf8());
}

//Успешное подключение
void TcpLayer::succsesConnectToDeamon(){
    socket->write("V0.0.1 visual start");
}

void TcpLayer::readHandler(){
    uint16_t size = socket->read(dataBuffer,maxSizeDataBuffer);
    QString tempStr;
    lst.clear();
    for(uint16_t i = 0; i<size; i++) {
        if(dataBuffer[i] != ':') {
            tempStr.push_back(dataBuffer[i]);
        }else {
            lst.push_back(tempStr);
            tempStr.clear();
        }
    }
    if(!tempStr.isEmpty()) lst.push_back(tempStr);
    emit receiveMessageFromServer(lst);
}


