#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //lullu
    ui->btn_round_game = (QPushButton *)ui->btn_round_game;
    ui->btn_round_game->setIconSize(QSize(ui->btn_round_game->size().width(),ui->btn_round_game->size().height()));
    QPixmap* pixmap1 = new QPixmap("/home/mofty/Dokumente/BA/programming_cpp/Demo/gamer-pc-65x65.jpg");
    QIcon icon1(*pixmap1);
    ui->btn_round_game->setIcon(icon1);


    ui->btn_swiss = (QPushButton *)ui->btn_swiss;
    ui->btn_swiss->setIconSize(QSize(ui->btn_swiss->size().width(),ui->btn_swiss->size().height()));
    QPixmap* pixmap2 = new QPixmap("/home/mofty/Dokumente/BA/programming_cpp/Demo/gamer-pc-65x65.jpg");
    QIcon icon2(*pixmap2);
    ui->btn_swiss->setIcon(icon2);

    ui->btn_FFA = (QPushButton *)ui->btn_FFA;
    ui->btn_FFA->setIconSize(QSize(ui->btn_FFA->size().width(),ui->btn_FFA->size().height()));
    QPixmap* pixmap3 = new QPixmap("/home/mofty/Dokumente/BA/programming_cpp/Demo/gamer-pc-65x65.jpg");
    QIcon icon3(*pixmap3);
    ui->btn_FFA->setIcon(icon3);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_FFA_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); //constants Page
}


void MainWindow::on_btn_swiss_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); //constants Page
}

