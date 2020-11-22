#ifndef ENGINE_HH
#define ENGINE_HH

#include "creategame.hh"
#include "core/logic.hh"
#include "city.h"

#include <memory>

namespace Student
{

class Engine
{
public:
    Engine();
    ~Engine();
    //std::shared_ptr<Student::City> createGame();
    void logic();

private:
    std::shared_ptr<Student::City> city_;
    std::shared_ptr<CourseSide::Logic> gameLogic_;
    // engineState = 0 default, after game start value is 1
    int engineState_;
};

}

#endif // ENGINE_HH
