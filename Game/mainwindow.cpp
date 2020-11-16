#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

namespace Student {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);

    map = new QGraphicsScene(this);
    ui->graphicsView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPicture(QImage img)
{
    map->setBackgroundBrush(img);
}

void MainWindow::addActor(int x, int y, int type)
{
    ActorItem* nActor = new ActorItem(x, y, type);
    actors_.push_back(nActor);
    map->addItem(nActor);
}

void MainWindow::moveActor(ActorItem *actor, int x, int y)
{
    actor->setPos(x, y);
}

Student::ActorItem* MainWindow::returnActorItem(int index)
{
    return actors_[index];
}

void MainWindow::drawStops(std::vector<std::shared_ptr<Interface::IStop>> stops)
{

    for (auto stop : stops) {
        QGraphicsPixmapItem *stopSprite = new QGraphicsPixmapItem(QPixmap(":/Resources/Graphics/stop.bmp"));
        int x = (stop->getLocation()).giveX();
        int y = 500 - (stop->getLocation()).giveY();
        stopSprite->setPos(x, y);
        map->addItem(stopSprite);
    }
}

}

