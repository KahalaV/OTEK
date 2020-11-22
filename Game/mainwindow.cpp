#include "mainwindow.h"
#include "ui_mainwindow.h"


namespace Student {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    score_(0),
    cloudStatus_(30)
{   
    ui->setupUi(this);
    ui->scoreLabel->setText(QString::number(score_));

    map = new QGraphicsScene(this);
    ui->graphicsView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimeLabel()));
    connect(timer, SIGNAL(timeout()), this, SLOT(movePlayer()));
    connect(timer, SIGNAL(timeout()), this, SLOT(moveClouds()));
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
    //movement
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

        //bombing
        case Qt::Key_Space:
            dropBomb();
    }
}
void MainWindow::movePlayer()
{
    int ss = player_->getSpeedStraight();
    int sd = player_->getSpeedDiagonal();
    switch (player_->getDir()) {
        case 1:
            if (player_->checkNewCoords(0, -ss)) {
                break;
            }
            player_->moveBy(0, -ss);
            break;
        case 2:
            if (player_->checkNewCoords(sd, -sd)) {
                break;
            }
            player_->moveBy(sd, -sd);
            break;
        case 3:
            if (player_->checkNewCoords(ss, 0)) {
                break;
            }
            player_->moveBy(ss, 0);
            break;
        case 4:
            if (player_->checkNewCoords(sd, sd)) {
                break;
            }
            player_->moveBy(sd, sd);
            break;
        case 5:
            if (player_->checkNewCoords(0, ss)) {
                break;
            }
            player_->moveBy(0, ss);
            break;
        case 6:
            if (player_->checkNewCoords(-sd, sd)) {
                break;
            }
            player_->moveBy(-sd, sd);
            break;
        case 7:
            if (player_->checkNewCoords(-ss, 0)) {
                break;
            }
            player_->moveBy(-ss, 0);
            break;
        case 8:
            if (player_->checkNewCoords(-sd, -sd)) {
                break;
            }
            player_->moveBy(-sd, -sd);
            break;
    }
}
void MainWindow::dropBomb()
{
    int bombX = player_->x() + player_->quadrantSide_;
    int bombY = player_->y() + player_->quadrantSide_;
    int bombRadius = player_->getBombRadius();

    for (auto actor : actors_) {
        int actorX = actor->x();
        int actorY = actor->y();
        int distance = sqrt((actorX - bombX)*(actorX - bombX) + (actorY-bombY)*(actorY-bombY));
        if (distance < bombRadius && actor->getType() == 1) {
            actor->setType(2);
            score_++;
            ui->scoreLabel->setText(QString::number(score_));
        }

    }

}
std::vector<int> MainWindow::randomizeCloudSlots()
{
    //first generate the amount of clouds (2-4)
    int cloudsAmount = (rand() % 3) + 2;

    //then generate the slots (0-11)
    std::vector<int> cloudSlots(12, 0);
    for (int i = 0; i < cloudsAmount;) {
        int slot = (rand() % 12) + 1;
        if (cloudSlots[slot - 1] == 0) {
            cloudSlots[slot - 1]  = 1;
            i++;
        } else {
            continue;
        }
    }
    return cloudSlots;
}
void MainWindow::addClouds()
{
    cloudStatus_ = 0;
    std::vector<int> cloudSlots = randomizeCloudSlots();
    for (int i = 0; i < 12; i++) {
        if (cloudSlots[i] == 1) {
            //add new cloud to the slot
            std::cout << "Adding cloud to the slot " << i << std::endl;
            Student::Cloud* cloud(new Student::Cloud(i * 50));
            clouds_.push_back(cloud);
            map->addItem(cloud);
        } else {
            continue;
        }
    }
}

void MainWindow::moveClouds()
{
    if (cloudStatus_ >= cloudInterval_) {
        cloudStatus_ = 0;
        addClouds();
    } else {
        cloudStatus_++;
    }

    for (auto cloud : clouds_) {
        if (cloud->x() < 0) {
            map->removeItem(cloud); //delete from scene
            clouds_.remove(clouds_.indexOf(cloud)); //delete from QVector
        } else {
            cloud->moveBy(-(cloud->getSpeed()), 0);
        }
    }
}
}
