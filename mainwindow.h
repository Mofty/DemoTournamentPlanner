#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QLineEdit>

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

    void handleEdits();

    void handleEditsAdded();

    void btnForwardFunc();

    void btnBackFunc();

    void on_btn_next_page2_clicked();

    void on_btn_FFA_clicked();

    void on_btn_back_page2_clicked();

private:
    void setIcons();
    void setUiForPagePlayers();
    void setUiForPageResult();

    QVBoxLayout *m_layout; //ly page 3
    QLineEdit *m_lineedit;
    QStringList strl_Namen;
    QStringList rr_Ergebniss;


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
