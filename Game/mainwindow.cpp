#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <QKeyEvent>

namespace Student {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
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

void MainWindow::addActor(int x, int y, int type)
{
    ActorItem* nActor = new ActorItem(x, y, type);
    actors_.push_back(nActor);
    map->addItem(nActor);
}

void MainWindow::addStop(int x, int y)
{
    QGraphicsPixmapItem* stopSprite = new QGraphicsPixmapItem(QPixmap(":/Resources/Graphics/stop.bmp"));
    stopSprite->setPos(x, y);
    map->addItem(stopSprite);
}

void MainWindow::moveActor(ActorItem *actor, int x, int y)
{
    actor->setPos(x, y);
}

Student::ActorItem* MainWindow::returnActorItem(int index)
{
    return actors_[index];
}
void MainWindow::updateTimeLabel(QTime clock)
{
    ui->timeLabel->setText(clock.toString("h:mm"));
}
void MainWindow::setPlayer(Student::Player* player)
{
    player_ = player;
    map->addItem(player_);
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_W:
            movePlayer(1);
            break;
        case Qt::Key_D:
            movePlayer(3);
            break;
        case Qt::Key_S:
            movePlayer(5);
            break;
        case Qt::Key_A:
            movePlayer(7);
            break;
    }
}
void MainWindow::movePlayer(int dir)
{
    int dx, dy = 0;
    switch (dir) {
        case 1:
            dx = 0;
            dy = -10;
            player_->setDirection(dir);
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 2:
            dx = 10;
            dy = -10;
            player_->setDirection(dir);
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 3:
            dx = 10;
            dy = 0;
            player_->setDirection(dir);
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 4:
            dx = 10;
            dy = 10;
            player_->setDirection(dir);
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 5:
            dx = 0;
            dy = 10;
            player_->setDirection(dir);
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 6:
            dx = -10;
            dy = 10;
            player_->setDirection(dir);
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 7:
            dx = -10;
            dy = 0;
            player_->setDirection(dir);
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 8:
            dx = -10;
            dy = -10;
            player_->setDirection(dir);
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
    }
    std::cout << "Player coords: x: " << player_->x_ << "y: " << player_->y_ << std::endl;
}

}


