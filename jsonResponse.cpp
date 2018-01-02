#include "jsonResponse.h"
#include <QJsonArray>
#include <QJsonDocument>

jsonResponse* jsonResponse::jsP = NULL;

jsonResponse* jsonResponse::getResponse(const QByteArray &str){
    if(jsP == NULL) jsP = new jsonResponse();
    QJsonDocument doc(QJsonDocument::fromJson(str));
    if(doc.isObject()) jsP->read(doc.object());
    return jsP;
}

void jsonResponse::read(const QJsonObject &jso){
    if(jso.contains("response") && jso["response"].isArray()) {
        respList.clear();
        auto array = jso["response"].toArray();
        for(auto it = array.constBegin(); it != array.constEnd(); ++it){
            if((*it).isString()) {
                respList.push_back((*it).toString());
            }
        }
    }
}

