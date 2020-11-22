#include "startwindow.h"
#include "engine.hh"
#include "city.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    //Student::StartWindow sw;
    //sw.show();

    //map image
    QImage bigMap = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    //QImage smallMap = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");

    CourseSide::Logic gameLogic;
    gameLogic.fileConfig();
    std::shared_ptr<Student::City> sanAndreas(new Student::City(bigMap));


    gameLogic.takeCity(sanAndreas);
    //gameLogic.setTime(12, 0); //for testing
    gameLogic.finalizeGameStart();

    //std::shared_ptr<Student::City> sanAndreas = Engine::createGame();
    //int gameStatus = Engine::engine(sanAndreas);

    return a.exec();
}
