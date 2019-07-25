#ifndef GRILLEMANUEL_H
#define GRILLEMANUEL_H

#include <QObject>
#include <QWidget>
#include <QVector>

#include "Point.h"

class GrilleManuel
{

public:
    GrilleManuel();
    int getSize();
    void addPoint(int x,int y);
    QPoint returnPoint(int i);
    void clear();

private:
    QVector<QPoint> listeCoins;
    int i;

};

#endif // GRILLEMANUEL_H
