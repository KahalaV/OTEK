#ifndef ENGINE_HH
#define ENGINE_HH

#include "creategame.hh"
#include "core/logic.hh"
#include "city.h"

#include <memory>

namespace Engine
{
    std::shared_ptr<Student::City> createGame();
    int engine(std::shared_ptr<Student::City>);
}

#endif // ENGINE_HH
