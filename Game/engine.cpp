#include "engine.hh"

namespace Engine
{
    std::shared_ptr<Student::City> createGame()
    {
        //map image
        QImage bigMap = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
        //QImage smallMap = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");

        std::shared_ptr<Student::City> sanAndreas(new Student::City(bigMap));

        return sanAndreas;
    }

    int engine(std::shared_ptr<Student::City> city)
    {
        CourseSide::Logic gameLogic;
        gameLogic.fileConfig();
        gameLogic.takeCity(city);
        //gameLogic.setTime(12, 0); //for testing
        gameLogic.finalizeGameStart();

        return 0;
    }
}
