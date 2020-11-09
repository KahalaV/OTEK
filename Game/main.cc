#include "core/logic.hh"
#include "city.h"
#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    //map images
    QImage basicMap = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage bigMap = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    //create mainwindow
    Student::MainWindow mw;
    mw.setPicture(bigMap);
    mw.show();

    //create city and game logic
    std::shared_ptr<Student::City> sanAndreas(new Student::City);
    CourseSide::Logic gameLogic;

    //start game
    gameLogic.fileConfig();
    gameLogic.takeCity(sanAndreas);
    gameLogic.finalizeGameStart();


    return a.exec();
}
