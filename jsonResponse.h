#ifndef JSONRESPONSE_H
#define JSONRESPONSE_H
#include <QJsonObject>
#include <QList>
#include <QByteArray>

class jsonResponse
{
public:
    QList<QString>&& getList() {return std::move(respList);}
    static jsonResponse* getResponse(const QByteArray& str);
    ~jsonResponse() { delete jsP; jsP=NULL; }
private:
    static jsonResponse* jsP;
    void read(const QJsonObject& jso);
    jsonResponse() {}
    QList<QString> respList;
};

#endif // JSONRESPONSE_H
