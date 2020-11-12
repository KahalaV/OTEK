#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
namespace Student {

MainWindow::MainWindow(QWidget *parent) :
    SimpleMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);

    map = new QGraphicsScene(this);
    ui->graphicsView->setScene(map);
    map->setSceneRect(0,0,width_,height_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPicture(QImage img)
{
    map->setBackgroundBrush(img);
}

void MainWindow::addStops(std::vector<std::shared_ptr<Interface::IStop>> stops)
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
