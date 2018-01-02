#include "TcpLayerr.h"
#include "jsonRequest.h"
#include "jsonResponse.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <widget.h>


TcpLayer::TcpLayer(uint16_t port, std::string ipAddress, QObject *parent) : ConnectionInterface(parent),
    socket(new QTcpSocket(this)),
    servPort(port),
    maxSizeDataBuffer(1024),
    protocolVersion("v0.0.1"){
    servAddr = ipAddress.c_str();
    //dataBuffer = new char(maxSizeDataBuffer);
    QObject::connect(socket,SIGNAL(connected()), this, SLOT(succsesConnectToDeamon()));
    QObject::connect(socket, SIGNAL(readyRead()),this, SLOT(readHandler()));
    socket->connectToHost(servAddr,servPort);
}

void TcpLayer::writeToDeamonMsg(const QString &msg){
    auto req = jsonRequest(protocolVersion);
    req.setRequest(msg);
    QJsonObject jso;
    socket->write(req.write(jso).toJson());
}

//Успешное подключение
void TcpLayer::succsesConnectToDeamon(){
    auto req = jsonRequest(protocolVersion);
    QJsonObject jso;
    socket->write(req.write(jso).toJson());
}

void TcpLayer::readHandler(){
    auto byteArray = socket->read(maxSizeDataBuffer);
    auto resp = jsonResponse::getResponse(byteArray);
    lst = resp->getList();
    emit receiveMessageFromServer(lst);
}


