#ifndef CITY_H
#define CITY_H

#include "interfaces/iactor.hh"
#include "interfaces/istop.hh"
#include "interfaces/icity.hh"
#include "actors/passenger.hh"
#include "mainwindow.h"

#include <QTime>
#include <iostream>
#include <iterator>

namespace Student
{

class City : public Interface::ICity
{
public:
    City(QImage &background);
    ~City();
    void setBackground(QImage& basicbackground, QImage& bigbackground);
    QImage getBackground();
    void setClock(QTime clock);
    void addStop(std::shared_ptr<Interface::IStop> stop);
    void startGame();
    void addActor(std::shared_ptr<Interface::IActor> newactor);
    void removeActor(std::shared_ptr<Interface::IActor> actor);
    void actorRemoved(std::shared_ptr<Interface::IActor> actor);
    bool findActor(std::shared_ptr<Interface::IActor> actor) const;
    void actorMoved(std::shared_ptr<Interface::IActor> actor);
    std::vector<std::shared_ptr<Interface::IActor> > getNearbyActors(Interface::Location loc) const;
    bool isGameOver() const;

private:
    QTime clock_;
    QImage &background_;
    std::shared_ptr<Student::MainWindow> mainWindow_;
    std::vector<std::shared_ptr<Interface::IActor>> actors_;
    std::vector<std::shared_ptr<Interface::IStop>> stops_;
    bool gamestatus_ = false;
};

}

#endif // CITY_H
