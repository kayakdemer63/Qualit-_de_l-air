/// @file mainwindow.h
/// @author Louan DESHAYES
/// @version 1.1
/// @class mainwindow

#ifndef MAINWINDOW_H
#define MAINWINDOW_H                        /// @def MAINWINDOW_H

#include <QMainWindow>                      /// @include <QMainWindow
#include <QNetworkReply>                    /// @include <QNetworkReply
#include <QNetworkAccessManager>            /// @include <QNetworkAccessManager
#include <QNetworkRequest>                  /// @include <QNetworkRequest
#include <QUrl>                             /// @include <QUrl
#include <QtGui>                            /// @include <QtGui
#include <QMessageBox>                      /// @include <QMessageBox
#include "qualite.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    qualite aqi;
    void message(int i);

private slots:
    void url_change();
    void search();
    void new_ville();
    void CB_change();
};
#endif // MAINWINDOW_H
