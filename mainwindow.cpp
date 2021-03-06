#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "roundrobin.h"
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QPushButton>
#include <QTableWidget>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setIcons();

    setUiForPagePlayers();
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

void MainWindow::handleEdits()
{
    disconnect(m_lineedit, SIGNAL (textEdited(QString)),this, SLOT (handleEdits()));
    QLineEdit* ledits = new QLineEdit;
    ledits->setMaximumHeight(25);
    ledits->setMaximumWidth(125);
    connect(ledits, SIGNAL (textEdited(QString)),this, SLOT (handleEditsAdded()));
    m_layout->addWidget(ledits);
}

void MainWindow::handleEditsAdded()
{
    QObject* obj = sender();
    disconnect(obj, SIGNAL(textEdited(QString)) , 0, 0);
    QLineEdit* ledits = new QLineEdit;
    ledits->setMaximumHeight(25);
    ledits->setMaximumWidth(125);
    connect(ledits, SIGNAL (textEdited(QString)),this, SLOT (handleEditsAdded()));
    m_layout->addWidget(ledits);
}

void MainWindow::setUiForPagePlayers()
{
    //container widget
    QWidget* qwidget = new QWidget;
    //ly of container widget
    m_layout = new QVBoxLayout(ui->page_tournyNames);
    m_layout->setSizeConstraint(QLayout::SetMinimumSize);
    //add Label "new Players"
    QLabel* lbltop = new QLabel;
    lbltop->setText("Enter Playernames: ");
    lbltop->setFont(QFont("Constantia", 12));
    m_layout->addWidget(lbltop);
    //add the first edit
    m_lineedit = new QLineEdit;
    m_lineedit->setMaximumHeight(25);
    m_lineedit->setMaximumWidth(125);
    connect(m_lineedit, SIGNAL (textEdited(QString)),this, SLOT (handleEdits()));
    m_layout->addWidget(m_lineedit);

    //layout zum widget hinzufuegen
    qwidget->setLayout(m_layout);
    //scroll prop
    QScrollArea * scroll = new QScrollArea;
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setWidgetResizable(false);
    scroll->setAlignment(Qt::AlignCenter);
    scroll->setWidget(qwidget);
    //scroll area layer add
    QVBoxLayout* vLayout = new QVBoxLayout(ui->page_tournyNames);
    vLayout->setSizeConstraint(QLayout::SetMinimumSize);
    vLayout->addWidget(scroll);

    QPushButton* btn_forward = new QPushButton("Next");
    btn_forward->setMaximumHeight(25);
    btn_forward->setMaximumWidth(100);
    connect(btn_forward, SIGNAL (clicked()),this, SLOT (btnForwardFunc()));
    vLayout->addWidget(btn_forward);

    QPushButton* btn_back = new QPushButton("Back");
    btn_back->setMaximumHeight(25);
    btn_back->setMaximumWidth(100);
    connect(btn_back, SIGNAL (clicked()),this, SLOT (btnBackFunc()));
    vLayout->addWidget(btn_back);

    QHBoxLayout* tmplayout = new QHBoxLayout(this);
    tmplayout->setContentsMargins(0, 0, 0, 0);
    tmplayout->addWidget(btn_back);
    tmplayout->addWidget(btn_forward);

    vLayout->addLayout(tmplayout);
}

void MainWindow::on_btn_next_page2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_tournyNames);
}

void MainWindow::on_btn_FFA_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_tournyConstants);
}

void MainWindow::btnForwardFunc()
{
    for (int i = 0; i < m_layout->count(); ++i)
    {
        QWidget *widget = m_layout->itemAt(i)->widget();
        QLineEdit* edit =  qobject_cast<QLineEdit*>(widget);

        if (edit != NULL)
        {
            strl_Namen << edit->text();
        }

    }

    RoundRobin* rr = new RoundRobin(ui->sB_GAMENUMPLAYER->value(), ui->sB_NUMPLAYER->value(), ui->sB_NUMROUND->value());

    //Ergebnissliste ; Teams-Trenner + Rundentrenner
    rr_Ergebniss  = rr->mainMethod();

    //Tabelle füllen
    setUiForPageResult();


    ui->stackedWidget->setCurrentWidget(ui->page_tournyResult);
}

void MainWindow::btnBackFunc()
{
    ui->stackedWidget->setCurrentWidget(ui->page_tournyConstants);
}

void MainWindow::on_btn_back_page2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_tournamentSelection);
}

void MainWindow::setUiForPageResult()
{
    int round = ui->sB_NUMROUND->value();

    QTableWidget *tw = new QTableWidget();
    tw->setColumnCount(5);
    QStringList fonts;
    fonts << "   Team Left    " << "   Points Left   " << ":" << "   Points Right   " << "   Team Right   ";
    tw->setHorizontalHeaderLabels(fonts);
    //resize to size
    tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Font in table
    QFont fnt;
    fnt.setPointSize(15);
    fnt.setFamily("Arial");
    tw->setFont(fnt);
    ui->page_tournyResult->setLayout(new QGridLayout);
    ui->page_tournyResult->layout()->addWidget(tw);

    for( int i = 0; i < round ; ++i ) {
        tw->insertRow( i );
        for( int j = 0; j < 5; ++j ) {

            QTableWidgetItem *item = new QTableWidgetItem();
            //alignment in den Cells
            item->setTextAlignment(Qt::AlignCenter);
            //alles readonly ausser Punkte
            if ( j == 1 || j == 3) {
                tw->setItem( i, j, item );
            } else {
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                tw->setItem( i, j, item );
            }
        }
    }

    QString zusammenfuegen;
    int l = 0;
    int semicoloncounter = ui->sB_GAMENUMPLAYER->value()* 2 + 2;;
    int RundeEnde=0;


    for (int i = 0; i < rr_Ergebniss.size(); i++) {

        if (QString::compare(rr_Ergebniss.at(i).toLocal8Bit().constData(), "+", Qt::CaseInsensitive) == 0) {
            RundeEnde = i + 1;
            break;
        }
    }

    for (int j = 0; j <= round - 1; j++) {

        for (int m = 0; m <= ui->sB_GAMENUMPLAYER->value(); m++) {


            QString str = rr_Ergebniss.at(l).toLocal8Bit().constData();

            if (str.toInt() || str == "0") {
                int a = str.toInt();
                zusammenfuegen.append(strl_Namen.value(a));
                zusammenfuegen.append(",");
            }

            l++;
        }

        l -= ui->sB_GAMENUMPLAYER->value();
        QTableWidgetItem *pCell = tw->item(j,0);
        zusammenfuegen = zusammenfuegen.remove(zusammenfuegen.length()-1, 1);
        pCell->setText(zusammenfuegen);
        l += semicoloncounter - 1;
        zusammenfuegen.clear();
    }

    zusammenfuegen.clear();
    l = ui->sB_GAMENUMPLAYER->value() + 1;;

    for (int j = 0; j <= round - 1; j++) {

        for (int m = 0; m <= ui->sB_GAMENUMPLAYER->value(); m++) {

            if (l > rr_Ergebniss.count() - 1) {
                break;
            }

            QString str = rr_Ergebniss.at(l).toLocal8Bit().constData();

            if (str.toInt() || str == "0") {
                int a = str.toInt();
                zusammenfuegen.append(strl_Namen.value(a));
                zusammenfuegen.append(",");
            }

            l++;
        }

        l -= ui->sB_GAMENUMPLAYER->value();
        QTableWidgetItem *pCell = tw->item(j,4);
        zusammenfuegen = zusammenfuegen.remove(zusammenfuegen.length()-1, 1);
        pCell->setText(zusammenfuegen);
        l += semicoloncounter - 1;
        zusammenfuegen.clear();
    }


}


