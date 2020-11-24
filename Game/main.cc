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

    std::shared_ptr<Student::Engine> gameEngine(new Student::Engine);
    gameEngine->logic();

    return a.exec();
}
