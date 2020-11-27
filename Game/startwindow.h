#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include <memory>

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
    void settingsChanged(QString name, int plane);

private:
    Ui::StartWindow *ui;
    QString playerName_;
    std::shared_ptr<QIcon> imageRedBaron_;
    std::shared_ptr<QIcon> imageBomber_;
    std::shared_ptr<QIcon> imageThunderbird_;
    int plane_; // 1 = Red Baron, 2 = Bomber, 3 = Thunderbird
};

}

#endif // STARTWINDOW_H
