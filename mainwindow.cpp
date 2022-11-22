/// @file mainwindow.cpp
/// @author Louan DESHAYES
/// @version 1.1
/// @class mainwindow

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::url_change()
{
    aqi.set_url(ui->url->toPlainText());
    search();
}

void MainWindow::message(int i)
{
    if (i >= 0 & i <=50)
    {
        ui->message->setText("Niveau de pollution de l'air : BON. \n\nLa qualité de l'air est jugée satisfaisante, et la pollution de l'air pose peu ou pas de risque.");
    }
    else if (i > 50 && i <=100)
    {
        ui->message->setText("Niveau de pollution de l'air : MODÉRÉ. \n\nLa qualité de l'air est acceptable. Cependant, pour certain polluant, il peut y avoir un risque sur la santé pour un très petit nombre de personnes inhabituellement sensible à la pollution atmosphérique.");
    }
    else if (i > 100 && i <=150)
    {
        ui->message->setText("Niveau de pollution de l'air : MAUVAIS POUR LES GROUPES SENSIBLES. \n\nLa qualité de l'air est acceptable. Cependant, pour certains polluants, il peutt y avoir un problème de santé modéré pour un très petit nombre de personnes qui sont particulièrement sensible à la pollution de l'air.");
    }
    else if (i > 150 && i <=200)
    {
        ui->message->setText("Niveau de pollution de l'air : MAUVAIS. \n\nTout le monde peut commencer à ressentir des effets sur la sant. Les membres des groupes sensibles peuvent ressentir des effets de santé plus graves.");
    }
    else if (i > 200 && i <=300)
    {
        ui->message->setText("Niveau de pollution de l'air : TRÈS MAUVAIS. \n\nAvertissements de santé de conditions d'urgence. toute la pollutionest plus susceptible d'être affecté.");
    }
    else if (i > 300)
    {
        ui->message->setText("Niveau de pollution de l'air : DANGEUREUX. \n\nAlerte de santé. Tout le monde peut ressentir des effets de santé plus graves.");
    }
}

void MainWindow::search()
{
    int i = aqi.get_qualite();
    ui->indice->display(i);
    message(i);
}

void MainWindow::new_ville()
{
    QString ville = ui->newVille->toPlainText();
    QString url = "https://api.waqi.info/feed/" + ville + "/?token=d9636de539c0cc32e3771e378fd51527b70526f1";
    qDebug() << url;
    aqi.set_url(url);
}

void MainWindow::CB_change()
{
    QString ville = ui->Ville_CB->currentText();
    QString url = "https://api.waqi.info/feed/" + ville + "/?token=d9636de539c0cc32e3771e378fd51527b70526f1";
    qDebug() << url;
    aqi.set_url(url);
}
