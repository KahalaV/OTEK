#include "engine.hh"

namespace Student
{

Engine::Engine(QObject *parent) :
    QObject(parent),
    gameLogic_(new CourseSide::Logic),
    startWindow_(new Student::StartWindow)
{
    city_ = std::shared_ptr<Student::City>(new Student::City);
    startWindow_->show();

    connect(startWindow_.get(), SIGNAL (settingsChanged(QString)), this, SLOT (settings(QString)));
    connect(this, SIGNAL (settingsChanged()), this, SLOT (logic()));
}

Engine::~Engine() {}

void Engine::setPlayerName(QString name)
{
    city_->setPlayerName(name);
}

void Engine::settings(QString name)
{
    setPlayerName(name);
    emit settingsChanged();
}

void Engine::logic()
{
    gameLogic_->fileConfig();
    gameLogic_->takeCity(city_);
    gameLogic_->setTime(12, 0); //for testing
    gameLogic_->finalizeGameStart();
}

}
