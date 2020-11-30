#include "startwindow.h"
#include "ui_startwindow.h"

namespace Student {

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow),
    imageRedBaron_(new QIcon(":/Resources/Graphics/red_baron.bmp")),
    imageBomber_(new QIcon(":/Resources/Graphics/bomber.bmp")),
    imageThunderbird_(new QIcon(":/Resources/Graphics/thunderbird.bmp"))
{
    ui->setupUi(this);
    ui->radioRedBaronButton->setIcon(*imageRedBaron_);
    ui->radioBomberButton->setIcon(*imageBomber_);
    ui->radioThunderbirdButton->setIcon(*imageThunderbird_);

    connect(ui->goButton, SIGNAL (released()), this, SLOT (setSettings()));
    connect(ui->lineEdit, SIGNAL (editingFinished()), this, SLOT(isNameOk()));
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

void StartWindow::isNameOk()
{
    if (!ui->lineEdit->text().isEmpty())
    {
        ui->goButton->setEnabled(true);
    }
    else
    {
        ui->goButton->setEnabled(false);
    }
}

}
