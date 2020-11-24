#include "engine.hh"

namespace Student
{

Engine::Engine() :
    gameLogic_(new CourseSide::Logic),
    engineState_(0)
{
    city_ = std::shared_ptr<Student::City>(new Student::City);
}

Engine::~Engine() {}

void Engine::logic()
{
    gameLogic_->fileConfig();
    gameLogic_->takeCity(city_);
    gameLogic_->setTime(12, 0); //for testing
    gameLogic_->finalizeGameStart();

    engineState_ = 1;
}

}
