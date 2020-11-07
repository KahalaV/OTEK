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

    void setPicture(QImage &img);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *map;

    int width_ = 1095;
    int height_ = 592;
};

}

#endif // MAINWINDOW_H
