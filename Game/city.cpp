#include "city.h"

namespace Student
{

City::City(QImage &background) :

    background_(background),
    mainWindow_(new Student::MainWindow)
{
    mainWindow_->setPicture(background_);
    mainWindow_->show();
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
}
void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    stops_.push_back(stop);
}
void City::startGame() {}
void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    actors_.push_back(newactor);
    int x = newactor->giveLocation().giveX();
    int y = 500 - newactor->giveLocation().giveY();
    mainWindow_->addActor(x, y, 1);

}
void City::removeActor(std::shared_ptr<Interface::IActor> actor) {}
void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{

}
bool City::findActor(std::shared_ptr<Interface::IActor> actor) const {}
void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    int x = actor->giveLocation().giveX();
    int y = 500 - actor->giveLocation().giveY();
    //City actors_ and MainWindow actors_ have the actors in the same order
    std::vector<std::shared_ptr<Interface::IActor>>::iterator it = std::find(actors_.begin(), actors_.end(), actor);
    int index = std::distance(actors_.begin(), it);

    Student::ActorItem *tempItem = mainWindow_->returnActorItem(index);
    mainWindow_->moveActor(tempItem, x, y);
}
std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const {}
bool City::isGameOver() const
{
    return false;
}

}
