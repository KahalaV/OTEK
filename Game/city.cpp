#include "city.h"
#include <iostream>
#include <QTime>

namespace Student
{

City::City(QImage &background) :

    background_(background)
{

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
}
void City::removeActor(std::shared_ptr<Interface::IActor> actor) {}
void City::actorRemoved(std::shared_ptr<Interface::IActor> actor) {}
bool City::findActor(std::shared_ptr<Interface::IActor> actor) const {}
void City::actorMoved(std::shared_ptr<Interface::IActor> actor) {}
std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const {}
bool City::isGameOver() const
{
    return false;
}
std::vector<std::shared_ptr<Interface::IStop>> City::returnStopVector()
{
    return stops_;
}

}
