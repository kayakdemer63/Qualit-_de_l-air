/// @file qualite.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class qualite

#ifndef QUALITE_H
#define QUALITE_H                                       /// @def QUALITE_H

#include <QNetworkReply>                                /// @include <QNetworkReply
#include <QNetworkAccessManager>                        /// @include <QNetworkAccessManager
#include <QNetworkRequest>                              /// @include <QNetworkRequest
#include <QUrl>                                         /// @include <QUrl
#include <QtGui>                                        /// @include <QtGui
#include <QMessageBox>                                  /// @include <QMessageBox
#include <QSslConfiguration>                            /// @include <QSslConfiguration

class qualite
{
public:
    qualite();
    /** @public @fn qualite()
     *  @brief Déclaration du Constructor.
     */

    void set_url(QString url);
    /** @public @fn void set_url(QString url)
     *  @brief Déclaration de la Méthode. Fonction permettant de définir l'url du Pixelit.
     *  @param[in] url L'url du Pixelit.
     */


    int get_qualite();

private:
    QUrl qurl;
    /** @private @var QUrl qurl
     *  @brief Déclaration de l'Attribut. Contient l'url du pixelit.
     */

    QByteArray get(QUrl url);
    /** @private @fn QByteArray get(QUrl url)
     *  @brief Déclaration de la Méthode. Fonction permettant d'obtenir l'url du pixelit.
     *  @param[in] url
     */

    QNetworkAccessManager m;

};

#endif // QUALITE_H
