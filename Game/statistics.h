#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <QTime>
#include <QDebug>

/**
 *@file
 *@brief
 */

namespace Student
{

const std::string RED_BARON = "Red Baron";
const std::string BOMBER = "Bomber";
const std::string THUNDERBIRD = "Thunderbird";

/**
 * @brief The Scores struct
 */
struct Scores {
    int score = 0;
    int nyssesDestroyed = 0;
    int cloudCollisions = 0;
    int healthRemaining = 0;
    int bombsDropped = 0;
    int nukesDropped = 0;
    std::string planeUsed = "";
    QTime gameTime = QTime();
};

/**
 * @brief The Statistics class saves game statistics
 */
class Statistics
{

public:
    explicit Statistics(QString &name);

    /**
     * @brief Destructor
     */
    ~Statistics();

    /**
     * @brief setScore
     * @param score
     */
    void setScore(int &score);

    /**
     * @brief setNyssesDestroyed
     * @param nyssesDestroyed
     */
    void setNyssesDestroyed(int &nyssesDestroyed);

    /**
     * @brief setCloudCollisions
     * @param cloudCollisions
     */
    void setCloudCollisions(int &cloudCollisions);

    /**
     * @brief setHealthRemaining
     * @param healthRemaining
     */
    void setHealthRemaining(int &healthRemaining);

    /**
     * @brief setBombsDropped
     * @param bombsDropped
     */
    void setBombsDropped(int &bombsDropped);

    /**
     * @brief setNukesDropped
     * @param nukesDropped
     */
    void setNukesDropped(int &nukesDropped);

    /**
     * @brief setPlaneUsed
     * @param planeUsed
     */
    void setPlaneUsed(int &planeUsed);

    /**
     * @brief setGameTime
     * @param gameTime
     */
    void setGameTime(QTime &gameTime);

    /**
     * @brief getScore
     * @return score
     */
    int getScore();

    /**
     * @brief getNyssesDestroyed
     * @return nysses destroyed
     */
    int getNyssesDestroyed();

    /**
     * @brief getCloudCollisions
     * @return cloud collisions
     */
    int getCloudCollisions();

    /**
     * @brief getHealthRemaining
     * @return health remaining
     */
    int getHealthRemaining();

    /**
     * @brief getBombsDropped
     * @return bombs dropped
     */
    int getBombsDropped();

    /**
     * @brief getNukesDropped
     * @return nukes dropped
     */
    int getNukesDropped();

    /**
     * @brief getPlaneUsed
     * @return plane used
     */
    std::string getPlaneUsed();

    /**
     * @brief getGameTime
     * @return game time
     */
    QTime getGameTime();

    /**
     * @brief writeStatistics
     */
    void writeStatistics();

    /**
     * @brief readStatistics
     */
    void readStatistics();

private:
    std::string fileName_;
    std::shared_ptr<Scores> scores_;
    QString playerName_;
    std::shared_ptr<std::map<QString, std::shared_ptr<Scores>>> highScores_;

    std::fstream createCsvFile();
};

}

#endif // STATISTICS_HH
