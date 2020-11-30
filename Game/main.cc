#include "startwindow.h"
#include "engine.h"
#include "city.h"
#include "endwindow.h"
#include "teststatistics.h"
#include <QApplication>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    std::shared_ptr<Student::TestStatistics> test(new Student::TestStatistics);

    std::shared_ptr<Student::Engine> gameEngine(new Student::Engine);

    return a.exec();

}
