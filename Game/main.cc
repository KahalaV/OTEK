#include "core/logic.hh"
#include "city.h"
#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    //map image
    //QImage bigMap = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    QImage smallMap = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");

    //create city and game logic
    std::shared_ptr<Student::City> sanAndreas(new Student::City(smallMap));
    CourseSide::Logic gameLogic;

    //create mainwindow
    Student::MainWindow mw;
    mw.setPicture(sanAndreas->getBackground());
    mw.show();

    //start game
    gameLogic.fileConfig();
    gameLogic.takeCity(sanAndreas);
    gameLogic.finalizeGameStart();

    //draw stops
    mw.addStops(sanAndreas->returnStopVector());


    return a.exec();
}
