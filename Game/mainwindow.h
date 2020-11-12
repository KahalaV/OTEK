#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graphics/simplemainwindow.hh"
#include "city.h"

/*!
 * Doxytest start
 */

namespace Ui {
class MainWindow;
}

namespace Student {

class MainWindow : public CourseSide::SimpleMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setPicture(QImage img);

    void addStops(std::vector<std::shared_ptr<Interface::IStop>> stops);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *map;

    int width_ = 500;
    int height_ = 500;
};

}

#endif // MAINWINDOW_H
