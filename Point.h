#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point();
    void setXY(int a,int b);
    int getX();
    int getY();

private:
    int x;
    int y;
};

#endif // POINT_H
