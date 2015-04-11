#ifndef ENEMYLASER_H
#define ENEMYLASER_H

#include "Ships.h"

class EnemyLaser
{
public:
    static const int R = 255;
    static const int G = 50;
    static const int B = 50;
    static const int W = 2;
    static const int H = 4;
    EnemyLaser(int x0, int y0)
        : x(x0), y(y0), exist(false), laser_speed(4)
    {}
    EnemyLaser()
    {
        (*this) = EnemyLaser(0, 0);
    }
    void set_x(const int & x0)
    {
        x = x0;
    }
    bool get_exist()
    {
        return exist;
    }
    void set_exist(const bool & x)
    {
        exist = x;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
    void set_y(const int & y0)
    {
        y = y0;
    }
    void set_laser_speed(const int & s)
    {
        laser_speed = s;
    }
    int get_laser_speed()
    {
        return laser_speed;
    }
private:
    int laser_speed;
    int x;
    int y;
    bool exist;
};

#endif
