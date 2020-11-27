#include "startwindow.h"
#include "ui_startwindow.h"

namespace Student {

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    connect(ui->goButton, SIGNAL (released()), this, SLOT (setSettings()));
    connect(this, SIGNAL (settingsChanged(QString, int)), this, SLOT (close()));
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::setSettings()
{
    playerName_ = ui->lineEdit->text();
    if (ui->radioRedBaronButton->isChecked())
    {
        plane_ = 1;
    }
    else if (ui->radioBomberButton->isChecked())
    {
        plane_ = 2;
    }
    else
    {
        plane_ = 3;
    }
    emit settingsChanged(playerName_, plane_);
}

}
