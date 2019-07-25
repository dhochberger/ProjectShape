#include "GrilleManuel.h"

GrilleManuel::GrilleManuel()
{
    i = 0;
}

int GrilleManuel::getSize(){
    return listeCoins.size();
}

void GrilleManuel::addPoint(int x,int y){
    QPoint p(x,y);
    listeCoins.push_back(p);
}

QPoint GrilleManuel::returnPoint(int i){
    return listeCoins.at(i);
}

void GrilleManuel::clear(){
    listeCoins.clear();
}
