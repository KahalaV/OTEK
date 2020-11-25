#include "endwindow.h"
#include "ui_endwindow.h"

namespace Student {

EndWindow::EndWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndWindow)
{
    ui->setupUi(this);

    connect(ui->quitButton, SIGNAL (released()), this, SLOT (quitButtonClicked()));
}

EndWindow::~EndWindow()
{
    delete ui;
}

void EndWindow::quitButtonClicked()
{
    std::exit(0);
}

}
