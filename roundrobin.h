#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include <QObject>
#include <QVector>

class RoundRobin : public QObject
{
    Q_OBJECT

public:
    explicit RoundRobin(int aGAMENUMPLAYER, int aNUMPLAYER, int aNUMROUND, QObject *parent = 0);

    QStringList mainMethod();

signals:

private:
    void count(int r, int i, int delta);
    void swap(int r, int i, int j);
    void validate();

    int ROUNDNUMPLAYER;
    int GAMENUMPLAYER;
    int NUMROUND;
    int NUMPLAYER;

    QVector< QVector<int> > Numgame;
    QVector< QVector<int> > Schedule;
    QVector<int> aux;
    QVector<int> xua;

    QStringList list_RobinResult;

    int Numunplayed;

public slots:
};


#endif // ROUNDROBIN_H
