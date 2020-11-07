#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Student {

MainWindow::MainWindow(QWidget *parent) :
    SimpleMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);

    map = new QGraphicsScene(this);
    ui->graphicsView->setScene(map);
    map->setSceneRect(0,0,width_,height_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}

}
