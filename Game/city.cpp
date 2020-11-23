#include "city.h"

namespace Student
{

City::City(QImage &background) :

    background_(background),
    mainWindow_(new Student::MainWindow)
{
    mainWindow_->setPicture(background_);
    mainWindow_->setClock(clock_);
    mainWindow_->show();
    setPlayer();

}
City::~City() {}

void City::setBackground(QImage& basicbackground, QImage& bigbackground) {};

QImage City::getBackground()
{
    return background_;
}
void City::setClock(QTime clock)
{
    clock_ = clock;
    mainWindow_->updateTimeLabel();
}
void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    stops_.push_back(stop);
    int x = stop->getLocation().giveX() + 353;
    int y = 500 - stop->getLocation().giveY() + 56;
    mainWindow_->addStop(x, y);
}
void City::startGame() {}
void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    mainWindow_->addActor(newactor);
}
void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    mainWindow_->removeActor(actor);
}
void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    //mikä vittu tämän idea on
}
bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    return mainWindow_->findActor(actor);
}
void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    int x = actor->giveLocation().giveX() + 353;
    int y = 500 - actor->giveLocation().giveY() + 56;

    mainWindow_->moveActor(actor, x, y);

}
std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const {}
bool City::isGameOver() const
{
    return false;
}
void City::setPlayer()
{
    Student::Player* player(new Student::Player());
    player_ = player;
    mainWindow_->setPlayer(player_);
}

}
