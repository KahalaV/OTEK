#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <iostream>
#include <fstream>
#include <string>
#include <QTime>

/**
 *@file
 *@brief
 */

namespace Student
{

class Statistics
{
public:
    Statistics();
    ~Statistics();

    void setScore(int score);
    void setNyssesDestroyed(int nyssesDestroyed);
    void setCloudCollisions(int cloudCollisions);
    void setHealthRemaining(int healthRemaining);
    void setBombsDropped(int bombsDropped);
    void setNukesDropped(int nukesDropped);
    void setPlaneUsed(int planeUsed);
    void setGameTime(QTime gameTime);

    void writeStatistics();
    void readStatistics();

private:
    int score_;
    int nyssesDestroyed_;
    int cloudCollisions_;
    int healthRemaining_;
    int bombsDropped_;
    int nukesDropped_;
    int planeUsed_;
    QTime gameTime_;

    std::fstream createCsvFile();
};

}

#endif // STATISTICS_HH
