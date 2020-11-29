#include "endwindow.h"
#include "ui_endwindow.h"

namespace Student {

EndWindow::EndWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndWindow),
    fileName_("statistics.csv"),
    highScores_(new std::vector<ScorePair>)
{
    ui->setupUi(this);
    readStatistics(fileName_);
    ui->playerNameLabel->setText(QString::fromStdString(row_.at(0)));
    ui->scoreLabel->setText(QString::fromStdString(row_.at(1)));
    ui->nyssesDestroyedLabel->setText(QString::fromStdString(row_.at(2)));
    ui->cloudCollisionsLabel->setText(QString::fromStdString(row_.at(3)));
    ui->healthRemainingLabel->setText(QString::fromStdString(row_.at(4)));
    ui->bombsDroppedLabel->setText(QString::fromStdString(row_.at(5)));
    ui->nukesDroppedLabel->setText(QString::fromStdString(row_.at(6)));
    ui->planeUsedLabel->setText(QString::fromStdString(row_.at(7)));
    ui->timePlayedLabel->setText(QString::fromStdString(row_.at(8)));

    connect(ui->quitButton, SIGNAL (released()), this, SLOT (quitButtonClicked()));
}
EndWindow::~EndWindow()
{
    delete ui;
}

void EndWindow::readStatistics(std::string &fileName)
{
    std::ifstream file;
    file.open(fileName);
    if (!file.is_open())
    {
        qDebug() << "Cannot open statistics file!";
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        row_ = Split::split(line, ',');
        std::string rowName = row_.at(0);
        int rowScore = stoi(row_.at(1));
        if (highScores_->size() == 0)
        {
            highScores_->push_back({rowName, rowScore});
        }
        else
        {
            std::vector<ScorePair>::iterator it;
            it = highScores_->begin();
            for (auto pair : *highScores_)
            {
                if (rowScore > pair.second)
                {
                    highScores_->insert(it, {rowName, rowScore});
                    break;
                }
                else
                {
                    if (it != highScores_->end())
                    {
                        it++;
                    }
                    continue;
                }
            }
            if (rowScore < highScores_->back().second)
            {
                highScores_->push_back({rowName, rowScore});
            }
        }
    }
}

void EndWindow::quitButtonClicked()
{
    std::exit(0);
}

}
