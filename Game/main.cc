#include "core/logic.hh"
#include "city.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    //map image
    //QImage bigMap = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    QImage smallMap = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");

    CourseSide::Logic gameLogic;
    gameLogic.fileConfig();
    std::shared_ptr<Student::City> sanAndreas(new Student::City(smallMap));

    gameLogic.takeCity(sanAndreas);
    gameLogic.finalizeGameStart();



    return a.exec();
}
