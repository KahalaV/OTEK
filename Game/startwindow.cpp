#include "startwindow.h"
#include "ui_startwindow.h"

namespace Student {

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    connect(ui->goButton, SIGNAL (released()), this, SLOT (setSettings()));
    connect(this, SIGNAL (settingsChanged(QString)), this, SLOT (close()));
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::setSettings()
{
    playerName_ = ui->lineEdit->text();
    emit settingsChanged(playerName_);
}

}
