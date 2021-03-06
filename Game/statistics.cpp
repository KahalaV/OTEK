#include "statistics.h"

namespace Student
{

Statistics::Statistics(QString &name) :
    fileName_("statistics.csv"),
    scores_(new Scores),
    playerName_(name),
    highScores_(new std::map<QString, std::shared_ptr<Scores>>)

{
    // Creating a Scores struct to contain the scores
    highScores_->insert({playerName_, scores_});
}

Statistics::~Statistics()
{

}

void Statistics::setScore(int &score)
{
    scores_->score = score;
}

void Statistics::setNyssesDestroyed(int &nyssesDestroyed)
{
    scores_->nyssesDestroyed = nyssesDestroyed;
}

void Statistics::setCloudCollisions(int &cloudCollisions)
{
    scores_->cloudCollisions = cloudCollisions;
}

void Statistics::setHealthRemaining(int &healthRemaining)
{
    scores_->healthRemaining = healthRemaining;
}

void Statistics::setBombsDropped(int &bombsDropped)
{
    scores_->bombsDropped = bombsDropped;
}

void Statistics::setNukesDropped(int &nukesDropped)
{
    scores_->nukesDropped = nukesDropped;
}

void Statistics::setPlaneUsed(int &planeUsed)
{
    if (planeUsed == 2)
    {
        scores_->planeUsed = BOMBER;
    }
    else if (planeUsed == 3)
    {
        scores_->planeUsed = THUNDERBIRD;
    }
    else
    {
        scores_->planeUsed = RED_BARON;
    }
}

void Statistics::setGameTime(QTime &gameTime)
{
    scores_->gameTime = gameTime;
}

int Statistics::getScore()
{
    return scores_->score;
}

int Statistics::getNyssesDestroyed()
{
    return scores_->nyssesDestroyed;
}

int Statistics::getCloudCollisions()
{
    return scores_->cloudCollisions;
}

int Statistics::getHealthRemaining()
{
    return scores_->healthRemaining;
}

int Statistics::getBombsDropped()
{
    return scores_->bombsDropped;
}

int Statistics::getNukesDropped()
{
    return scores_->nukesDropped;
}

std::string Statistics::getPlaneUsed()
{
    return scores_->planeUsed;
}

QTime Statistics::getGameTime()
{
    return scores_->gameTime;
}

void Statistics::writeStatistics()
{
    std::fstream statisticsFile = createCsvFile();

    if (statisticsFile.is_open())
    {
        statisticsFile << playerName_.toStdString() << ",";
        statisticsFile << highScores_->at(playerName_)->score << ",";
        statisticsFile << highScores_->at(playerName_)->nyssesDestroyed << ",";
        statisticsFile << highScores_->at(playerName_)->cloudCollisions << ",";
        statisticsFile << highScores_->at(playerName_)->healthRemaining << ",";
        statisticsFile << highScores_->at(playerName_)->bombsDropped << ",";
        statisticsFile << highScores_->at(playerName_)->nukesDropped << ",";
        statisticsFile << highScores_->at(playerName_)->planeUsed << ",";
        statisticsFile << highScores_->at(playerName_)->gameTime.toString("m:ss").toStdString() << "\n";
    }
    statisticsFile.close();
    qDebug() << "statistics.csv closed";
}

std::fstream Statistics::createCsvFile()
{
    // Creating and/or opening the file
    std::fstream statisticsFile;
    statisticsFile.open(fileName_, std::ios_base::app);
    if (!statisticsFile.is_open())
    {
        return std::fstream();
    }
    else
    {
        qDebug() << "Opened statistics.csv";
        return statisticsFile;
    }
}

}
