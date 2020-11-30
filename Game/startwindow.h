#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include <QPixmap>
#include <memory>

/**
 *@file
 *@brief
 */

namespace Ui {
class StartWindow;
}

namespace Student {

/**
 * @brief The StartWindow class defines the dialog that appears at the start of the game
 */
class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     */
    ~StartWindow();

public slots:
    /**
     * @brief Sets player name and plane type
     */
    void setSettings();
    /**
     * @brief isNameOk
     */
    void isNameOk();

signals:
    /**
     * @brief Emits player information
     * @param name: player name
     * @param plane: plane type
     */
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
