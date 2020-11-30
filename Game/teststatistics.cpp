#include "teststatistics.h"

namespace Student
{

TestStatistics::TestStatistics(QObject *parent) :
    QObject(parent),
    testerName_("Tester"),
    stats_(new Student::Statistics(testerName_)),
    testInt_(100),
    testInt2_(-1),
    testInt3_(30),
    testString_(3),
    testTime_(QTime(0,1,2,3))
{
    QTest::qExec(this);
}

TestStatistics::~TestStatistics()
{

}

void TestStatistics::testSetScore()
{
    QCOMPARE(stats_->getScore(), 0);
    stats_->setScore(testInt_);
    QCOMPARE(stats_->getScore(), testInt_);
}

void TestStatistics::testSetNyssesDestroyed()
{
    QCOMPARE(stats_->getNyssesDestroyed(), 0);
    stats_->setNyssesDestroyed(testInt2_);
    QCOMPARE(stats_->getNyssesDestroyed(), testInt2_);
}

void TestStatistics::testSetCloudCollisions()
{
    QCOMPARE(stats_->getCloudCollisions(), 0);
    stats_->setCloudCollisions(testInt3_);
    QCOMPARE(stats_->getCloudCollisions(), testInt3_);
}

void TestStatistics::testSetHealthRemaining()
{
    QCOMPARE(stats_->getHealthRemaining(), 0);
    stats_->setHealthRemaining(testInt3_);
    QCOMPARE(stats_->getHealthRemaining(), testInt3_);
}

void TestStatistics::testSetBombsDropped()
{
    QCOMPARE(stats_->getBombsDropped(), 0);
    stats_->setBombsDropped(testInt_);
    QCOMPARE(stats_->getBombsDropped(), testInt_);

}

void TestStatistics::testSetNukesDropped()
{
    QCOMPARE(stats_->getNukesDropped(), 0);
    stats_->setNukesDropped(testInt2_);
    QCOMPARE(stats_->getNukesDropped(), testInt2_);
}

void TestStatistics::testSetPlaneUsed()
{
    QCOMPARE(stats_->getPlaneUsed(), "");
    stats_->setPlaneUsed(testString_);
    QCOMPARE(stats_->getPlaneUsed(), THUNDERBIRD);
}

void TestStatistics::testSetGameTime()
{
    QCOMPARE(stats_->getGameTime(), QTime());
    stats_->setGameTime(testTime_);
    QCOMPARE(stats_->getGameTime(), testTime_);
}

}
