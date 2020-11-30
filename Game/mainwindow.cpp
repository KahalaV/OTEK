#include "mainwindow.h"
#include "ui_mainwindow.h"

const int PLAYER_ADJUST = 25; //offset of player image
const int NYSSE_X_ADJUST = 11; //offset of nysse image
const int NYSSE_Y_ADJUST = 6; //offset of nysse image

namespace Student {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    playerName_(""),
    nuke_(new Student::Nuke()),
    gameTime_(0),
    score_(0),
    nyssesDestroyed_(0),
    cloudCollisions_(0),
    bombsDropped_(0),
    nukesDropped_(0),
    cloudStatus_(30),
    gameOver_(false)

{
    ui->setupUi(this);
    ui->scoreLabel->setText(QString::number(score_));
    setWindowTitle("Boom! Stop the Nysse");
    std::srand(std::time(nullptr)); //set rng seed

    map = new QGraphicsScene(this);
    ui->graphicsView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    nukeStatus = new QGraphicsScene(this);
    ui->nukeGraphicsView->setScene(nukeStatus);
    nukeStatus->setSceneRect(0,0,31,31);
    nukeStatus->setBackgroundBrush(QImage(":/Resources/Graphics/noNuke.bmp"));

    ui->graphicsView->scale(2,2);
    ui->graphicsView->viewport()->installEventFilter(this);

    QSound::play(":/Resources/Sound/gameMusic.wav");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
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
void MainWindow::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    //check type
    int type = 0; //0 = passenger, 1 = nysse
    if (std::dynamic_pointer_cast<CourseSide::Passenger>(newactor) == nullptr)
    {
        type = 1;
    }
    int x = newactor->giveLocation().giveX() + 353 - NYSSE_X_ADJUST;
    int y = 556 - newactor->giveLocation().giveY() - NYSSE_Y_ADJUST;
    ActorItem* nActorItem = new ActorItem(x, y, type);

    actors_.push_back(std::make_pair(newactor, nActorItem));
    map->addItem(nActorItem);
}
void MainWindow::addStop(int x, int y)
{
    QGraphicsPixmapItem* stopSprite = new QGraphicsPixmapItem(QPixmap(":/Resources/Graphics/stop.bmp"));
    stopSprite->setPos(x, y);
    stopSprite->setZValue(0.1);
    map->addItem(stopSprite);
}
void MainWindow::moveActor(std::shared_ptr<Interface::IActor> actor)
{
    int x = actor->giveLocation().giveX() + 353 - NYSSE_X_ADJUST;
    int y = 556 - actor->giveLocation().giveY() - NYSSE_Y_ADJUST;
    auto it = std::find_if(actors_.begin(), actors_.end(), [&actor](const std::pair<std::shared_ptr<Interface::IActor>, ActorItem*>& elem){ return elem.first == actor;});
    //to show passenger amount
    it->second->setPassengerCount((std::dynamic_pointer_cast<CourseSide::Nysse>(actor)->getPassengers().size()));

    //if the item is a destroyed bus, ActorItem is set to nullptr to stop the movement
    if (it->second->getType() == 2) {
        return;
    } else {
        it->second->setX(x);
        it->second->setY(y);
    }
}
void MainWindow::updateTimeLabel()
{
    ui->timeLabel->setText(clock_->toString("h:mm"));
}
void MainWindow::setPlayer(Student::Player* player)
{
    player_ = player;
    map->addItem(player_);
    ui->graphicsView->centerOn(player_);
    ui->bombsLeftLabel->setText(QString::number(player_->getBombs()));
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //movement
    int dir = player_->getDir();
    switch (event->key()) {
        case Qt::Key_W:
            if (1 <= dir && dir <= 4) {
                dir--;
                if (dir == 0) {
                    dir = 8;
                }
            }
            if (6 <= dir && dir <= 8) {
                dir++;
                if (dir == 9) {
                    dir = 1;
                }
            }
            player_->setDirection(dir);
            break;

        case Qt::Key_D:
            if (4 <= dir && dir  <= 6) {
                dir--;
                if (dir == 0) {
                    dir = 8;
                }
            }
            if ((1 <= dir && dir <= 2) || dir == 8) {
                dir++;
                if (dir == 9) {
                    dir = 1;
                }
            }
            player_->setDirection(dir);
            break;

        case Qt::Key_S:
            if (6 <= dir && dir <= 8) {
                dir--;
                if (dir == 0) {
                    dir = 8;
                }
            }
            if (2 <= dir && dir <= 4) {
                dir++;
                if (dir == 9) {
                    dir = 1;
                }
            }
            player_->setDirection(dir);
            break;

        case Qt::Key_A:
            if ((1 <= dir && dir <= 2) || dir == 8) {
                dir--;
                if (dir == 0) {
                    dir = 8;
                }
            }
            if (4 <= dir && dir <= 6) {
                dir++;
                if (dir == 9) {
                    dir = 1;
                }
            }
            player_->setDirection(dir);
            break;

        //bombing
        case Qt::Key_Space:
            dropBomb();
            break;

        //nuking
        case Qt::Key_R:
            dropNuke();
            break;

        //error
        case Qt::Key_E:
            QSound::play(":/Resources/Sound/error.wav");
            break;
        case Qt::Key_Q:
            QSound::play(":/Resources/Sound/error.wav");
            break;

    }
}
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui->graphicsView->viewport() && event->type() == QEvent::Wheel)
    {
        return true;
    } else {
        return false;
    }
}
void MainWindow::movePlayer()
{
    //move player
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

    //check nuke collection
    if (nuke_->getStatus() == 1 && player_->collidesWithItem(nuke_)) {
        QSound::play(":/Resources/Sound/nukeGained.wav");
        map->removeItem(nuke_);
        nuke_->setStatus(2);
        nukeStatus->setBackgroundBrush(QImage(":/Resources/Graphics/nukeReady.bmp"));
    }

    //check collision with clouds
    for (auto cloud : clouds_) {
        if (player_->collidesWithItem(cloud)) {
            if (player_->getCooldown() <= 0) {
                //if the player has not recently taken hit
                player_->setCooldown(30);
                QSound::play(":/Resources/Sound/cloudHitSound.wav");
                score_ -= 5;
                //score will not go below 0
                if (score_ < 0) {
                    score_ = 0;
                }
                cloudCollisions_++;
                ui->scoreLabel->setText(QString::number(score_));
                player_->decreaseHealth();
                ui->healthBar->setValue(player_->getHealth()*25);
                if (player_->healthLeft()) {
                    gameOver_ = true;
                }
            } else {
                return;
            }

        }
    }
}
void MainWindow::dropBomb()
{
    if (player_->getBombs() < 1) {
        return;
    }

    player_->dropBomb();
    int x = player_->x();
    int y = player_->y();

    Student::Bomb* bomb(new Student::Bomb);
    bomb->setPos(x, y);
    bomb->setDirection(player_->getDir());
    bombs_.push_back(bomb);
    map->addItem(bomb);
    QSound::play(":/Resources/Sound/bombDrop.wav");
    bombsDropped_++;
}
void MainWindow::setPlayerName(QString &name)
{
    playerName_ = name;
    ui->playerLabel->setText(name);
}

void MainWindow::setPlaneType(int &plane)
{
    planeType_ = plane;
}

void MainWindow::setStatistics()
{
    statistics_ = std::shared_ptr<Student::Statistics>(
                new Student::Statistics(playerName_));
    statistics_->setScore(score_);
    statistics_->setNyssesDestroyed(nyssesDestroyed_);
    statistics_->setCloudCollisions(cloudCollisions_);
    int health = player_->getHealth()*25;
    statistics_->setHealthRemaining(health);
    statistics_->setBombsDropped(bombsDropped_);
    statistics_->setNukesDropped(nukesDropped_);
    statistics_->setPlaneUsed(planeType_);
    QTime timePlayed = QTime(0, gameTime_/60, gameTime_%60, 0).addMSecs(
                -timeLeft_.msecsSinceStartOfDay());
    statistics_->setGameTime(timePlayed);
    statistics_->writeStatistics();
}
void MainWindow::updateBombs()
{
    for (auto bomb : bombs_) {
        if (!bomb->isExploded()) {
            //if the bomb has not exploded yet
            bomb->setScale(bomb->getDropTime()*0.15);
            bomb->decreaseDropTime();
            if (bomb->getDropTime() == 0) {
                bomb->explode();
                QSound::play(":/Resources/Sound/explosion.wav");

                //check nearby actors and destroy buses within explosion radius
                checkExplosionHits(bomb->x() + PLAYER_ADJUST, bomb->y() + PLAYER_ADJUST, player_->getBombRadius());
            }
        } else {
            //if the bomb has exploded
            bomb->setScale((bomb->getExplosionTime())*0.2);
            bomb->increaseExplosionTime();
            if (bomb->getExplosionTime() == 10) {
                map->removeItem(bomb); //delete from scene
                bombs_.remove(bombs_.indexOf(bomb)); //delete from QVector
            }
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
void MainWindow::removeActor(std::shared_ptr<Interface::IActor> actor) {
    auto it = std::find_if(actors_.begin(), actors_.end(), [&actor](const std::pair<std::shared_ptr<Interface::IActor>, ActorItem*>& elem){ return elem.first == actor;});
    it->first->remove();
    map->removeItem(it->second);
    actors_.erase(it);
}
bool MainWindow::findActor(std::shared_ptr<Interface::IActor> actor)
{
    if (std::find_if(actors_.begin(), actors_.end(), [&actor](const std::pair<std::shared_ptr<Interface::IActor>, ActorItem*>& elem){ return elem.first == actor;})) {
        return true;
    } else {
        return false;
    }
}
void MainWindow::decreaseGameTime()
{
    timeLeft_ = timeLeft_.addMSecs(-tick_);
    ui->timeLeftLabel->setText(timeLeft_.toString("mm:ss"));

    ui->graphicsView->centerOn(player_);

    if (timeLeft_ == QTime(0,0,0,0)) {
        gameOver_ = true;
        timer->stop();
    } else {
        return;
    }
}
void MainWindow::startGame(const int GAME_TIME)
{
    gameTime_ = GAME_TIME;
    timeLeft_ = QTime(0, GAME_TIME/60, GAME_TIME%60, 0);
    ui->timeLeftLabel->setText(timeLeft_.toString("mm:ss"));
    timer->start(tick_);
}
bool MainWindow::isGameOver()
{
    if (gameOver_)
    {
        timer->stop();
        setStatistics();
    }
    return gameOver_;
}
void MainWindow::update()
{
    //move player
    movePlayer();

    //increase bombs
    player_->addBombs();
    ui->bombsLeftLabel->setText(QString::number(player_->getBombs()));

    //update currently dropping and exploding bombs
    updateBombs();

    //update dropping nuke
    updateNuke();

    //move clouds
    moveClouds();

    //if player has cooldown left, decrease cooldown
    if (player_->getCooldown() > 0) {
        player_->decreaseCooldown();
    }

    //if player doesn't have a nuke, spawn nuke
    if (nuke_->getStatus() == 0) {
        spawnNuke();
    }

    //decrease game time left
    decreaseGameTime();
}
void MainWindow::spawnNuke()
{
    //randomize location
    int x = (rand() % 895) + 50;
    int y = (rand() % 452) + 50;

    nuke_->setStatus(1);
    nuke_->setPos(x,y);
    map->addItem(nuke_);
}
void MainWindow::dropNuke()
{
    //player needs to have a nuke collected
    if (nuke_->getStatus() != 2)
    {
        return;
    }

    nuke_->setStatus(3);
    nukeStatus->setBackgroundBrush(QImage(":/Resources/Graphics/noNuke.bmp"));
    int x = player_->x();
    int y = player_->y();
    nuke_->setPos(x, y);
    nuke_->setDirection(player_->getDir());
    map->addItem(nuke_);
    nukesDropped_++;
}
void MainWindow::updateNuke()
{
    if (nuke_->getStatus() != 3) {
        return;
    }

    if (!nuke_->isExploded()) {
        //if the bomb has not exploded yet
        nuke_->setScale(nuke_->getDropTime()*0.15);
        nuke_->decreaseDropTime();
        if (nuke_->getDropTime() == 0) {
            nuke_->explode();
            QSound::play(":/Resources/Sound/explosion.wav");

            //check nearby actors and destroy buses within explosion radius
            checkExplosionHits(nuke_->x() + PLAYER_ADJUST, nuke_->y() + PLAYER_ADJUST, nuke_->getExplosionRadius());
        }
    } else {
        //if the bomb has exploded
        nuke_->setScale((nuke_->getExplosionTime())*0.4);
        nuke_->increaseExplosionTime();
        if (nuke_->getExplosionTime() == 10) {
            map->removeItem(nuke_); //delete from scene
            nuke_->setStatus(0);
        }
    }

}
void MainWindow::checkExplosionHits(int x, int y, int radius)
{
    for (auto actor : actors_) {
        int actorX = actor.second->x() + NYSSE_X_ADJUST;
        int actorY = actor.second->y() + NYSSE_Y_ADJUST;
        //euclidean distance
        int distance = sqrt((actorX - x)*(actorX - x) + (actorY-y)*(actorY-y));
        if (distance < radius && actor.second->getType() == 1) {
            actor.second->setType(2);
            //one point for nysse and one for every passenger
            score_ += std::dynamic_pointer_cast<CourseSide::Nysse>(actor.first)->getPassengers().size() + 1;
            nyssesDestroyed_++;
            ui->scoreLabel->setText(QString::number(score_));
        }
    }
    //test: draw ellipse that marks the explosion radius
    //map->addEllipse(x - radius, y - radius, 2*radius, 2*radius);
}

}
