#ifndef ENGINE_HH
#define ENGINE_HH

#include "creategame.hh"
#include "core/logic.hh"
#include "city.h"
#include "startwindow.h"

#include <QObject>

#include <memory>

namespace Student
{

class Engine : public QObject
{
    Q_OBJECT

public:
    explicit Engine(QObject *parent = nullptr);
    ~Engine();

    void setPlayerName(QString name);
    //std::shared_ptr<Student::City> createGame();

public slots:
    void initCity(QString name);
    void logic();
    void startGame();

signals:
    void cityInitialized();
    void gameStartFinalized();

private:
    std::shared_ptr<Student::City> city_;
    std::shared_ptr<CourseSide::Logic> gameLogic_;
    std::shared_ptr<Student::StartWindow> startWindow_;
    // engineState = 0 default, after game start value is 1
    // int engineState_;
};

}

#endif // ENGINE_HH
