#include "engine.hh"

namespace Student
{

Engine::Engine(QObject *parent) :
    QObject(parent),
    gameLogic_(new CourseSide::Logic),
    startWindow_(new Student::StartWindow),
    city_(nullptr)
{
    // city_ = std::shared_ptr<Student::City>(new Student::City);
    startWindow_->show();

    connect(startWindow_.get(), SIGNAL (settingsChanged(QString)), this, SLOT (initCity(QString)));
    connect(this, SIGNAL (cityInitialized()), this, SLOT (logic()));
    connect(this, SIGNAL (gameStartFinalized()), this, SLOT (startGame()));
}

Engine::~Engine() {}

void Engine::setPlayerName(QString name)
{
    city_->setPlayerName(name);
}

void Engine::initCity(QString name)
{
    city_ = std::shared_ptr<Student::City>(new Student::City);
    setPlayerName(name);
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
