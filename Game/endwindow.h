#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QDialog>
#include "stdlib.h"

namespace Ui {
class EndWindow;
}

namespace Student {

class EndWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EndWindow(QWidget *parent = nullptr);
    ~EndWindow();

public slots:
    void quitButtonClicked();

private:
    Ui::EndWindow *ui;
};

}

#endif // ENDWINDOW_H
