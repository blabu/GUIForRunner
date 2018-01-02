#ifndef REQUESTJSON_H
#define REQUESTJSON_H

#include <QString>
#include <QJsonObject>
#include <QJsonDocument>

class jsonRequest
{
public:
    jsonRequest(QString version);
    QString getRequest() const {return request;}
    QString getVersion() const {return Version;}
    void setRequest(const QString& str) { request = str; }
    jsonRequest *read(const QJsonObject &json);
    QJsonDocument write(QJsonObject &json) const;
private:
    QString Version;
    QString request;
};

#endif // REQUESTJSON_H
