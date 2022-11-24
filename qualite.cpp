/// @file qualite.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class qualite

#include "qualite.h"

qualite::qualite()
{
    qurl = "https://api.waqi.info/feed/clermont-ferrand/?token=d9636de539c0cc32e3771e378fd51527b70526f1";
}

void qualite::set_url(QString url)
{
    qurl = QUrl(url);
    qDebug() << qurl;
}

QByteArray qualite::get(QUrl url)
{
    QNetworkRequest requete(url);

    QSslConfiguration config= QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    requete.setSslConfiguration(config);

    QNetworkReply *reply = m.get(requete);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();
    return read;
}

int qualite::get_qualite()
{
    QUrl url = qurl;

    QJsonDocument docJSON = QJsonDocument::fromJson(get(url));

    qDebug() << docJSON;

    QJsonObject objetJSON = docJSON.object();
    qDebug() << objetJSON;
    QJsonObject jData = objetJSON.value("data").toObject();
    qDebug() << jData;
    QJsonValue jQualite = jData.value("aqi");
    qDebug() << jQualite;
    return jQualite.toDouble();
}
