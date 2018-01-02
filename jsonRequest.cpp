#include "jsonRequest.h"

jsonRequest::jsonRequest(QString version):Version(version)
{

}

jsonRequest* jsonRequest::read(const QJsonObject &json){
    if (json.contains("version") && json["version"].isString())
            Version = json["version"].toString();

    if (json.contains("request") && json["request"].isString())
            request = json["request"].toString();
    return this;
}

QJsonDocument jsonRequest::write(QJsonObject &json) const{
    json["version"] = Version;
    json["request"] = request;
    return QJsonDocument(json);
}
