/// @file qualite.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class qualite

#ifndef QUALITE_H
#define QUALITE_H                       /// @def QUALITE_H

#include <QNetworkReply>                /// @include <QNetworkReply
#include <QNetworkAccessManager>        /// @include <QNetworkAccessManager
#include <QNetworkRequest>              /// @include <QNetworkRequest
#include <QUrl>                         /// @include <QUrl
#include <QtGui>                        /// @include <QtGui
#include <QMessageBox>                  /// @include <QMessageBox
#include <QSslConfiguration>            /// @include <QSslConfiguration

class qualite
{
public:
    qualite();
    /** @public @fn qualite()
     *  @brief Déclaration du Constructor.
     */

    void set_url(QString url);
    /** @public @fn void set_url(QString url)
     *  @brief Déclaration de la Méthode. Fonction permettant de définir l'url du site et la ville.
     *  @param[in] url L'url du site et la ville.
     */


    int get_qualite();
    /** @public @fn int get_qualite()
     *  @brief Déclaration de la Méthode. Fonction permettant de récupérer l'indice de qualité de l'air à partir du fichier Json.
     *  @param[out] jQualite.toDouble
     */

private:
    QUrl qurl;
    /** @private @var QUrl qurl
     *  @brief Déclaration de l'Attribut. Contient l'url du site et la ville.
     */

    QByteArray get(QUrl url);
    /** @private @fn QByteArray get(QUrl url)
     *  @brief Déclaration de la Méthode. Fonction permettant d'envoyer une requête à l'url du site et la ville.
     *  @param[in] url L'url du site et la ville
     */

    QNetworkAccessManager m;
    /** @private @fn QNetworkAccessManager m
     *  @brief Déclaration de l'Attibut.
     */

};

#endif // QUALITE_H
