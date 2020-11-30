#include "engine.h"

namespace Student
{

Engine::Engine(QObject *parent) :
    QObject(parent),
    city_(nullptr),
    gameLogic_(new CourseSide::Logic),
    startWindow_(new Student::StartWindow)
{
    startWindow_->show();

    connect(startWindow_.get(), SIGNAL (settingsChanged(QString, int)), this, SLOT (initCity(QString, int)));
    connect(this, SIGNAL (cityInitialized()), this, SLOT (logic()));
    connect(this, SIGNAL (gameStartFinalized()), this, SLOT (startGame()));
}
Engine::~Engine() {}
void Engine::initCity(QString name, int plane)
{
    city_ = std::shared_ptr<Student::City>(new Student::City);
    city_->setPlayerName(name);
    city_->setPlaneType(plane);
    emit cityInitialized();
}
void Engine::logic()
{
    gameLogic_->fileConfig();
    gameLogic_->takeCity(city_);
    gameLogic_->setTime(12, 0); //for testing
    gameLogic_->finalizeGameStart();
    emit gameStartFinalized();
}
void Engine::startGame()
{
    city_->startGame();
}

}
