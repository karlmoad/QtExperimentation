//
// Created by Moad, Karl on 2/13/18.
//

#ifndef QTEXPERIMENTATION_UTILITIES_H
#define QTEXPERIMENTATION_UTILITIES_H


#include <QUuid>
#include <QCryptographicHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

class Utilities{
public :
    static const QString toSHA1Hash(const QString &data){
        return QString(QCryptographicHash::hash(data.toUtf8(), QCryptographicHash::Sha1).toHex());
    }

    static const QString generateNewKey(){
        return QUuid::createUuid().toString();
    }

    static const QString serializeJsonToString(const QJsonObject &json){
        QJsonDocument jdoc = QJsonDocument(json);
        return QString::fromUtf8(jdoc.toJson(QJsonDocument::JsonFormat::Compact));
    }

    static const QJsonObject deserializeStringToJson(const QString &json){
        QJsonDocument jobj = QJsonDocument::fromJson(json.toUtf8());
        return jobj.object();
    }
};

#endif //QTEXPERIMENTATION_UTILITIES_H
