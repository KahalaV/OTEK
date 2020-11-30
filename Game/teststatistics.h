#ifndef TESTSTATISTICS_H
#define TESTSTATISTICS_H

#include "statistics.h"

#include <memory>
#include <QObject>
#include <QString>
#include <QTest>

namespace Student
{

class TestStatistics : public QObject
{
    Q_OBJECT

public:
    explicit TestStatistics(QObject *parent = nullptr);
    ~TestStatistics();

private slots:
    void testSetScore();
    void testSetNyssesDestroyed();
    void testSetCloudCollisions();
    void testSetHealthRemaining();
    void testSetBombsDropped();
    void testSetNukesDropped();
    void testSetPlaneUsed();
    void testSetGameTime();

private:
    QString testerName_;
    std::shared_ptr<Student::Statistics> stats_;
    int testInt_;
    int testInt2_;
    int testInt3_;
    int testString_;
    QTime testTime_;
};

}

#endif // TESTSTATISTICS_H
