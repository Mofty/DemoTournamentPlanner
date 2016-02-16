#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_FFA_clicked();

    void on_btn_round_game_clicked();

    void on_btn_swiss_clicked();

    void on_btn_back_FFA_clicked();

    void on_btn_next_FFA_clicked();

    void on_sB_player_editingFinished();

    void on_sB_device_editingFinished();

    void on_sB_round_editingFinished();

private:
    void setIcons();
    QSpinBox *sB_player;
    QSpinBox *sB_device;
    QSpinBox *sB_round;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
