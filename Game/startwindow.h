#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>

namespace Ui {
class StartWindow;
}

namespace Student {

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

public slots:
    void setSettings();

signals:
    void settingsChanged(QString name);

private:
    Ui::StartWindow *ui;
    QString playerName_;
};

}

#endif // STARTWINDOW_H
