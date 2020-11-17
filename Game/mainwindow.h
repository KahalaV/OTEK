#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "actoritem.h"
#include "interfaces/istop.hh"
#include "interfaces/iactor.hh"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>

/*!
 * Doxytest start
 */

namespace Ui {
class MainWindow;
}

namespace Student {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setPicture(QImage img);
    void addActor(int x, int y, int type);
    void addStop(int x, int y);
    void moveActor(ActorItem *actor, int x, int y);
    Student::ActorItem* returnActorItem(int index);

    void drawStops(std::vector<std::shared_ptr<Interface::IStop>> stops);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QVector<Student::ActorItem*> actors_;

    int width_ = 500;
    int height_ = 500;
};

}

#endif // MAINWINDOW_H
