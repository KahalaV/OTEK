#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <QTime>
#include <QDebug>
#include <QtTest/QTest>

/**
 *@file
 *@brief
 */

namespace Student
{

const std::string RED_BARON = "Red Baron";
const std::string BOMBER = "Bomber";
const std::string THUNDERBIRD = "Thunderbird";

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

class Statistics : public QObject
{
    Q_OBJECT
public:
    explicit Statistics(QString &name, QObject *parent = nullptr);
    ~Statistics();

    void setScore(int &score);
    void setNyssesDestroyed(int &nyssesDestroyed);
    void setCloudCollisions(int &cloudCollisions);
    void setHealthRemaining(int &healthRemaining);
    void setBombsDropped(int &bombsDropped);
    void setNukesDropped(int &nukesDropped);
    void setPlaneUsed(int &planeUsed);
    void setGameTime(QTime &gameTime);

    void writeStatistics();
    void readStatistics();

private slots:
    void testStats();
    void testAnother();

private:
    std::string fileName_;
    std::shared_ptr<Scores> scores_;
    QString playerName_;
    std::shared_ptr<std::map<QString, std::shared_ptr<Scores>>> highScores_;


//    int score_;
//    int nyssesDestroyed_;
//    int cloudCollisions_;
//    int healthRemaining_;
//    int bombsDropped_;
//    int nukesDropped_;
//    int planeUsed_;
//    QTime gameTime_;

    std::fstream createCsvFile();
};

}

#endif // STATISTICS_HH
