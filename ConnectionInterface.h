#ifndef CONNECTIONINTERFACE_H
#define CONNECTIONINTERFACE_H

#include <QObject>

class ConnectionInterface : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionInterface(QObject *parent = 0);
    virtual ~ConnectionInterface()=default;
signals:
    void receiveMessageFromServer(const QList<QString>);
public slots:
    virtual void writeToDeamonMsg(const QString& msg) = 0;
};

#endif // CONNECTIONINTERFACE_H
