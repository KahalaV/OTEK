#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimeLabel()));
    connect(timer, SIGNAL(timeout()), this, SLOT(movePlayer()));
    timer->start(tick_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPicture(QImage img)
{
    map->setBackgroundBrush(img);
}
void MainWindow::setClock(QTime &clock)
{
    clock_ = &clock;
    ui->timeLabel->setText(clock_->toString("h:mm"));
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
void MainWindow::updateTimeLabel()
{
    ui->timeLabel->setText(clock_->toString("h:mm"));
}
void MainWindow::setPlayer(Student::Player* player)
{
    player_ = player;
    map->addItem(player_);
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int dir = player_->getDir();
    switch (event->key()) {
        case Qt::Key_W:
            if (dir == 2 || dir == 8) {
                player_->setDirection(1);
                break;
            } if (dir == 7) {
                player_->setDirection(8);
                break;
            } if (dir == 3) {
                player_->setDirection(2);
                break;
            } else {
                break;
            }

        case Qt::Key_D:
            if (dir == 2 || dir == 4) {
                player_->setDirection(3);
                break;
            } if (dir == 1) {
                player_->setDirection(2);
                break;
            } if (dir == 5) {
                player_->setDirection(4);
                break;
            } else {
                break;
            }


        case Qt::Key_S:
            if (dir == 6 || dir == 4) {
                player_->setDirection(5);
                break;
            } if (dir == 7) {
                player_->setDirection(6);
                break;
            } if (dir == 3) {
                player_->setDirection(4);
                break;
            } else {
                break;
            }

        case Qt::Key_A:
            if (dir == 6 || dir == 8) {
                player_->setDirection(7);
                break;
            } if (dir == 1) {
                player_->setDirection(8);
                break;
            } if (dir == 5) {
                player_->setDirection(6);
                break;
            } else {
                break;
            }
    }
}
void MainWindow::movePlayer()
{
    int dx, dy = 0;
    switch (player_->getDir()) {
        case 1:
            dx = 0;
            dy = -10;
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 2:
            dx = 7;
            dy = -7;
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 3:
            dx = 10;
            dy = 0;
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 4:
            dx = 7;
            dy = 7;
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 5:
            dx = 0;
            dy = 10;
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 6:
            dx = -7;
            dy = 7;
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 7:
            dx = -10;
            dy = 0;
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
        case 8:
            dx = -7;
            dy = -7;
            if (player_->checkNewCoords(dx, dy)) {
                break;
            }
            player_->updateCoords(dx, dy);
            player_->moveBy(dx, dy);
            break;
    }
}
}


