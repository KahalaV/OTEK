#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include "split.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <memory>

#include <QDebug>
#include <QDialog>
#include "stdlib.h"

/**
 *@file
 *@brief
 */

namespace Ui {
class EndWindow;
}

namespace Student {

typedef std::pair<std::string, int> ScorePair;

/**
 * @brief The EndWindow class displays game stats and ends execution of the game
 */
class EndWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EndWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     */
    ~EndWindow();

    /**
     * @brief readStatistics reads statistics from a file
     * @param fileName
     */
    void readStatistics(std::string &fileName);

    /**
     * @brief displayStats displays statistics of the last game
     */
    void displayStats();

    /**
     * @brief displayTopTen displays top ten highscores
     */
    void displayTopTen();

public slots:
    void quitButtonClicked();

private:
    Ui::EndWindow *ui;
    std::string fileName_;
    std::vector<std::string> row_; // Row of data in stats file
    std::shared_ptr<std::vector<ScorePair>> highScores_;
};

}

#endif // ENDWINDOW_H
