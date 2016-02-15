#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sB_player = new QSpinBox;

    setIcons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setIcons()
{
    ui->btn_round_game = (QPushButton *)ui->btn_round_game;
    ui->btn_round_game->setIconSize(QSize(ui->btn_round_game->size().width(),ui->btn_round_game->size().height()));
    QPixmap* pixmap1 = new QPixmap(QDir::currentPath() + "/Wezzoo-Icon-65x65.jpg");
    QIcon icon1(*pixmap1);
    ui->btn_round_game->setIcon(icon1);

    ui->btn_swiss = (QPushButton *)ui->btn_swiss;
    ui->btn_swiss->setIconSize(QSize(ui->btn_swiss->size().width(),ui->btn_swiss->size().height()));
    QPixmap* pixmap2 = new QPixmap(QDir::currentPath() + "/bla.png");
    QIcon icon2(*pixmap2);
    ui->btn_swiss->setIcon(icon2);

    ui->btn_FFA = (QPushButton *)ui->btn_FFA;
    ui->btn_FFA->setIconSize(QSize(ui->btn_FFA->size().width(),ui->btn_FFA->size().height()));
    QPixmap* pixmap3 = new QPixmap(QDir::currentPath() + "/gamer-pc-65x65.jpg");
    QIcon icon3(*pixmap3);
    ui->btn_FFA->setIcon(icon3);

}

void MainWindow::on_btn_FFA_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); //constants Page
}

void MainWindow::on_btn_round_game_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); //constants Page
}

void MainWindow::on_btn_swiss_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); //constants Page
}

void MainWindow::on_btn_back_FFA_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); //constants Page
}

void MainWindow::on_btn_next_FFA_clicked()
{
    ui->stackedWidget->setCurrentIndex(4); //constants Page
}

void MainWindow::on_sB_player_editingFinished()
{

   // valuePlayer->value();
    //int player = players->value();
    qWarning() << "player: " << QSpinBox::value(sB_player);
}

void MainWindow::on_sB_device_editingFinished()
{
   // int devices = QSpinBox::value();

    //qWarning << "devices: " << devices;
}

void MainWindow::on_sB_round_editingFinished()
{
 //   int rounds = QSpinBox::value();
  //  qWarning << "rounds: " << rounds;
}
