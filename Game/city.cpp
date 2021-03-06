#include "city.h"

namespace Student
{

City::City(const int GAME_TIME) :
    mainWindow_(new Student::MainWindow),
    gameTime_(GAME_TIME)
{
    mainWindow_->setPicture(QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png"));
    mainWindow_->setClock(clock_);
    mainWindow_->show();
    setPlayer();
}
City::~City()
{

}
void City::setBackground(QImage& basicbackground, QImage& bigbackground)
{
    Q_UNUSED(basicbackground);
    Q_UNUSED(bigbackground);
}
void City::setClock(QTime clock)
{
    clock_ = clock;
    mainWindow_->updateTimeLabel();
}
void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    int x = stop->getLocation().giveX() + 353;
    int y = 500 - stop->getLocation().giveY() + 56;
    mainWindow_->addStop(x, y);
}
void City::startGame()
{
    mainWindow_->startGame(gameTime_);
}
void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    if (std::dynamic_pointer_cast<CourseSide::Passenger>(newactor) == nullptr) {
        mainWindow_->addActor(newactor);
    }
}
void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    if (std::dynamic_pointer_cast<CourseSide::Passenger>(actor) == nullptr) {
        mainWindow_->removeActor(actor);
    }
}
void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    Q_UNUSED(actor);
}
bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    if (std::dynamic_pointer_cast<CourseSide::Passenger>(actor) == nullptr) {
        return mainWindow_->findActor(actor);
    } else {
        return false;
    }
}
void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    if (std::dynamic_pointer_cast<CourseSide::Passenger>(actor) == nullptr) {
        mainWindow_->moveActor(actor);
    }
}
std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{
    Q_UNUSED(loc);
    return {};
}
bool City::isGameOver() const
{
    if (mainWindow_->isGameOver()) {
        mainWindow_->close();
        std::shared_ptr<Student::EndWindow> endWindow(new Student::EndWindow);
        endWindow->exec();
        return true;
    } else {
        return false;
    }
}
void City::setPlayer()
{
    Student::Player* player(new Student::Player());
    player_ = player;
    mainWindow_->setPlayer(player_);
}
void City::setPlayerName(QString &name)
{
    playerName_ = name;
    mainWindow_->setPlayerName(name);
}
void City::setPlaneType(int &plane)
{
    planeType_ = plane;
    mainWindow_->setPlaneType(plane);
    player_->setPlaneType(plane);
}
void City::endGame() const
{
    std::shared_ptr<Student::EndWindow> endWindow(new Student::EndWindow);
    endWindow->exec();
}

}
