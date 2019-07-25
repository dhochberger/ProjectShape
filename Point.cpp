#include "Point.h"

Point::Point()
{
    x=0;
    y=0;
}

void Point::setXY(int a,int b){
    x = a;
    y = b;
}

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}
