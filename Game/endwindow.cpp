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
    displayStats();
    displayTopTen();

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

void EndWindow::displayStats()
{
    ui->playerNameLabel->setText(QString::fromStdString(row_.at(0)));
    ui->scoreLabel->setText(QString::fromStdString(row_.at(1)));
    ui->nyssesDestroyedLabel->setText(QString::fromStdString(row_.at(2)));
    ui->cloudCollisionsLabel->setText(QString::fromStdString(row_.at(3)));
    ui->healthRemainingLabel->setText(QString::fromStdString(row_.at(4)));
    ui->bombsDroppedLabel->setText(QString::fromStdString(row_.at(5)));
    ui->nukesDroppedLabel->setText(QString::fromStdString(row_.at(6)));
    ui->planeUsedLabel->setText(QString::fromStdString(row_.at(7)));
    ui->timePlayedLabel->setText(QString::fromStdString(row_.at(8)));
}

void EndWindow::displayTopTen()
{
    for (unsigned int i = 0; (i < 10 && i < highScores_->size()); i++)
    {
        if (i == 0)
        {
            ui->topTenPlayerOneLabel->setText(QString::fromStdString(highScores_->at(i).first));
            ui->topTenScoreOneLabel->setText(QString::fromStdString(std::to_string(highScores_->at(i).second)));
        }
        else if (i == 1)
        {
            ui->topTenPlayerTwoLabel->setText(QString::fromStdString(highScores_->at(i).first));
            ui->topTenScoreTwoLabel->setText(QString::fromStdString(std::to_string(highScores_->at(i).second)));
        }
        else if (i == 2)
        {
            ui->topTenPlayerThreeLabel->setText(QString::fromStdString(highScores_->at(i).first));
            ui->topTenScoreThreeLabel->setText(QString::fromStdString(std::to_string(highScores_->at(i).second)));
        }
        else if (i == 3)
        {
            ui->topTenPlayerFourLabel->setText(QString::fromStdString(highScores_->at(i).first));
            ui->topTenScoreFourLabel->setText(QString::fromStdString(std::to_string(highScores_->at(i).second)));
        }
        else if (i == 4)
        {
            ui->topTenPlayerFiveLabel->setText(QString::fromStdString(highScores_->at(i).first));
            ui->topTenScoreFiveLabel->setText(QString::fromStdString(std::to_string(highScores_->at(i).second)));
        }
        else if (i == 5)
        {
            ui->topTenPlayerSixLabel->setText(QString::fromStdString(highScores_->at(i).first));
            ui->topTenScoreSixLabel->setText(QString::fromStdString(std::to_string(highScores_->at(i).second)));
        }
        else if (i == 6)
        {
            ui->topTenPlayerSevenLabel->setText(QString::fromStdString(highScores_->at(i).first));
            ui->topTenScoreSevenLabel->setText(QString::fromStdString(std::to_string(highScores_->at(i).second)));
        }
        else if (i == 7)
        {
            ui->topTenPlayerEightLabel->setText(QString::fromStdString(highScores_->at(i).first));
            ui->topTenScoreEightLabel->setText(QString::fromStdString(std::to_string(highScores_->at(i).second)));
        }
        else if (i == 8)
        {
            ui->topTenPlayerNineLabel->setText(QString::fromStdString(highScores_->at(i).first));
            ui->topTenScoreNineLabel->setText(QString::fromStdString(std::to_string(highScores_->at(i).second)));
        }
        else if (i == 9)
        {
            ui->topTenPlayerFourLabel->setText(QString::fromStdString(highScores_->at(i).first));
            ui->topTenScoreFourLabel->setText(QString::fromStdString(std::to_string(highScores_->at(i).second)));
        }
        else
        {
            ui->topTenPlayerTenLabel->setText(QString::fromStdString(highScores_->at(i).first));
            ui->topTenScoreTenLabel->setText(QString::fromStdString(std::to_string(highScores_->at(i).second)));
        }
    }
}

void EndWindow::quitButtonClicked()
{
    std::exit(0);
}

}
