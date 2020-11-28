#include "statistics.hh"

namespace Student
{

Statistics::Statistics() :
    score_(0),
    nyssesDestroyed_(0),
    cloudCollisions_(0),
    healthRemaining_(0),
    bombsDropped_(0),
    nukesDropped_(0),
    planeUsed_(0),
    gameTime_(QTime())
{

}

Statistics::~Statistics()
{

}

void Statistics::setScore(int score)
{
    score_ = score;
}

void Statistics::setNyssesDestroyed(int nyssesDestroyed)
{
    nyssesDestroyed_ = nyssesDestroyed;
}

void Statistics::setCloudCollisions(int cloudCollisions)
{
    cloudCollisions_ = cloudCollisions;
}

void Statistics::setHealthRemaining(int healthRemaining)
{
    healthRemaining_ = healthRemaining;
}

void Statistics::setBombsDropped(int bombsDropped)
{
    bombsDropped_ = bombsDropped;
}

void Statistics::setNukesDropped(int nukesDropped)
{
    nukesDropped_ = nukesDropped;
}

void Statistics::setPlaneUsed(int planeUsed)
{
    planeUsed_ = planeUsed;
}

void Statistics::setGameTime(QTime gameTime)
{
    gameTime_ = gameTime;
}

void Statistics::writeStatistics()
{
    std::fstream statisticsFile = createCsvFile();

    if (statisticsFile.is_open())
    {
        statisticsFile << score_ << ",";
        statisticsFile << nyssesDestroyed_ << ",";
        statisticsFile << cloudCollisions_ << ",";
        statisticsFile << healthRemaining_ << ",";
        statisticsFile << bombsDropped_ << ",";
        statisticsFile << nukesDropped_ << ",";
        statisticsFile << planeUsed_ << ",";
        statisticsFile << gameTime_.toString().toStdString() << "\n";
    }
    statisticsFile.close();
}

std::fstream Statistics::createCsvFile()
{
    std::fstream statisticsFile;
    statisticsFile.open("statistics.csv", std::ios_base::in | std::ios_base::out);
    if (statisticsFile.is_open())
    {
        std::string line;
        if (!getline(statisticsFile, line))
        {
            statisticsFile << "Statistics for games played\n";
            statisticsFile << "SCORE,NYSSES DESTROYED,CLOUD COLLISIONS,"
                              "HEALTH REMAINING,BOMBS DROPPED,NUKES DROPPED,"
                              "PLANE USED,GAME TIME\n";
        }
        return statisticsFile;
    }

    return std::fstream();
}

}
