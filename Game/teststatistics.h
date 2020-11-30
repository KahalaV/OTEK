#ifndef TESTSTATISTICS_H
#define TESTSTATISTICS_H

#include "statistics.h"

#include <memory>
#include <QObject>
#include <QString>
#include <QTest>

/**
 *@file
 *@brief
 */

namespace Student
{

/**
 * @brief The TestStatistics class is a unit testing class for Student::Statistics 's setting functions using QCOMPARE()
 */
class TestStatistics : public QObject
{
    Q_OBJECT

public:
    explicit TestStatistics(QObject *parent = nullptr);

    /**
     * @brief Destructor
     */
    ~TestStatistics();

private slots:
    /**
     * @brief testSetScore
     */
    void testSetScore();

    /**
     * @brief testSetNyssesDestroyed
     */
    void testSetNyssesDestroyed();

    /**
     * @brief testSetCloudCollisions
     */
    void testSetCloudCollisions();

    /**
     * @brief testSetHealthRemaining
     */
    void testSetHealthRemaining();

    /**
     * @brief testSetBombsDropped
     */
    void testSetBombsDropped();

    /**
     * @brief testSetNukesDropped
     */
    void testSetNukesDropped();

    /**
     * @brief testSetPlaneUsed
     */
    void testSetPlaneUsed();

    /**
     * @brief testSetGameTime
     */
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
