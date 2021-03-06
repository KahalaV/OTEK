#ifndef ENGINE_HH
#define ENGINE_HH

#include "creategame.hh"
#include "core/logic.hh"
#include "city.h"
#include "startwindow.h"

#include <QObject>

#include <memory>

/**
 *@file
 *@brief
 */

namespace Student
{

/**
 * @brief The Engine class creates the City object and the Logic object and initializes and launches game execution
 */
class Engine : public QObject
{
    Q_OBJECT

public:
    explicit Engine(QObject *parent = nullptr);

    /**
     * @brief Destructor
     */
    ~Engine();

public slots:
    void initCity(QString name, int plane);
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
