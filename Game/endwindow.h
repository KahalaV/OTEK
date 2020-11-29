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

namespace Ui {
class EndWindow;
}

namespace Student {

typedef std::pair<std::string, int> ScorePair;

class EndWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EndWindow(QWidget *parent = nullptr);
    ~EndWindow();

    void readStatistics(std::string &fileName);

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
