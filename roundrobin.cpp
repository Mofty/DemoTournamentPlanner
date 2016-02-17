#include "roundrobin.h"

RoundRobin::RoundRobin(int aGAMENUMPLAYER, int aNUMPLAYER, int aNUMROUND, QObject *parent ) : QObject(parent)
{
    GAMENUMPLAYER = aGAMENUMPLAYER;
    NUMPLAYER = aNUMPLAYER;
    NUMROUND = aNUMROUND;
    ROUNDNUMPLAYER = NUMPLAYER - NUMPLAYER % GAMENUMPLAYER;
    Numunplayed = (NUMPLAYER * (NUMPLAYER - 1)) / 2;

    aux = QVector<int>(NUMPLAYER);
    Schedule = QVector<QVector<int> >(NUMROUND, aux);

    xua = QVector<int>(NUMPLAYER);
    Numgame = QVector<QVector<int> >(NUMPLAYER, xua);
}

void RoundRobin::count(int r, int i, int delta) {
    int start;
    int stop;
    int j;
    if (i >= ROUNDNUMPLAYER) return;
    start = i - i % GAMENUMPLAYER;
    stop = start + GAMENUMPLAYER;
    for (j = start; j < stop; j++) {
        int p;
        int q;
        if (j == i) continue;
        p = Schedule[r][i];
        q = Schedule[r][j];
        if (q < p) {
            int t;
            t = p;
            p = q;
            q = t;
        }
        if (Numgame[p][q] == 0) Numunplayed--;
        Numgame[p][q] += delta;
        if (Numgame[p][q] == 0) Numunplayed++;
    }
}

void RoundRobin::swap(int r, int i, int j) {
    int t;
    count(r, i, -2);
    count(r, j, -2);
    t = Schedule[r][i];
    Schedule[r][i] = Schedule[r][j];
    Schedule[r][j] = t;
    count(r, i, 2);
    count(r, j, 2);
}

QStringList RoundRobin::mainMethod() {
    int r;
    for (r = 0; r < NUMROUND; r++) {
        int i;
        for (i = 0; i < NUMPLAYER; i++) {
            int j;
            j = rand() % (i + 1);
            Schedule[r][i] = Schedule[r][j];
            Schedule[r][j] = i;
        }
        for (i = 0; i < NUMPLAYER; i++) count(r, i, 1);
    }
    while (Numunplayed > 0) {
        int r;
        int i;
        int j;
        int previous;
        r = rand() % NUMROUND;
        i = rand() % NUMPLAYER;
        j = rand() % NUMPLAYER;
        previous = Numunplayed;
        swap(r, i, j);
        if (Numunplayed < previous) {
            //fprintf(stderr, "%d\n", Numunplayed);
        }
        else if (Numunplayed > previous) {
            swap(r, i, j);
        }
    }
    for (r = 0; r < NUMROUND; r++) {

        if (r != 0) {
            list_RobinResult.append("+");
        }

        int i;

        for (i = 0; i < NUMPLAYER; i++) {

            if (i % GAMENUMPLAYER == 0 && i != 0) {
                list_RobinResult.append(";");
            }

            list_RobinResult.append(QString::number(Schedule[r][i]));
        }

    }
    return list_RobinResult;
}
