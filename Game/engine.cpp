#include "engine.hh"

namespace Student
{

Engine::Engine() :
    gameLogic_(new CourseSide::Logic),
    engineState_(0)
{
    //map image
    QImage bigMap = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    //QImage smallMap = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    city_ = std::shared_ptr<Student::City>(new Student::City(bigMap));
}

Engine::~Engine() {}

void Engine::logic()
{
    gameLogic_->fileConfig();
    gameLogic_->takeCity(city_);
    //gameLogic.setTime(12, 0); //for testing
    gameLogic_->finalizeGameStart();

    engineState_ = 1;
}

}
