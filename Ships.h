#ifndef SHIPS_H
#define SHIPS_H

#include "Image.h"
#include "Rect.h"

const int LSR_MAX = 30;
const int SHIPS_MAX = 10;

class AquaAlien
{
public:
    AquaAlien()
        : image("images/galaxian/GalaxianAquaAlien.gif"),
          rect(image.getRect()), alive(true), attack(false)
    {}
    void kill()
    {
        alive = false;
    }
    bool is_alive()
    {
        return alive;
    }
    void set_x(const int & x)
    {
        rect.x = x;
    }
    void set_y(const int & y)
    {
        rect.y = y;
    }
    Image & get_image()
    {
        return image;
    }
    Rect & get_rect()
    {
        return rect;
    }
private:
    Image image;
    Rect rect;
    bool alive;
    bool attack;
};

class RedAlien
{
public:
    RedAlien()
        : image("images/galaxian/GalaxianRedAlien.gif"),
          rect(image.getRect()), alive(true), attack(false)
    {}
    void kill()
    {
        alive = false;
    }
    bool is_alive()
    {
        return alive;
    }
    void set_x(const int & x)
    {
        rect.x = x;
    }
    void set_y(const int & y)
    {
        rect.y = y;
    }
    Image & get_image()
    {
        return image;
    }
    Rect & get_rect()
    {
        return rect;
    }
private:
    Image image;
    Rect rect;
    bool alive;
    bool attack;
};

class PurpleAlien
{
public:
    PurpleAlien()
        : image("images/galaxian/GalaxianPurpleAlien.gif"),
          rect(image.getRect()), alive(true), attack(false)
    {}
    void kill()
    {
        alive = false;
    }
    bool is_alive()
    {
        return alive;
    }
    void set_x(const int & x)
    {
        rect.x = x;
    }
    void set_y(const int & y)
    {
        rect.y = y;
    }
    Image & get_image()
    {
        return image;
    }
    Rect & get_rect()
    {
        return rect;
    }
private:
    Image image;
    Rect rect;
    bool alive;
    bool attack;
};

class FlagShip
{
public:
    FlagShip()
        : image("images/galaxian/GalaxianFlagship.gif"),
          rect(image.getRect()), alive(true), attack(false)
    {}
    void kill()
    {
        alive = false;
    }
    bool is_alive()
    {
        return alive;
    }
    void set_x(const int & x)
    {
        rect.x = x;
    }
    void set_y(const int & y)
    {
        rect.y = y;
    }
    Image & get_image()
    {
        return image;
    }
    Rect & get_rect()
    {
        return rect;
    }
private:
    Image image;
    Rect rect;
    bool alive;
    bool attack;
};

class Galaxip
{
public:
    Galaxip()
        : image("images/galaxian/GalaxianGalaxip.gif"),
          rect(image.getRect()), alive(true)
    {}
    void kill()
    {
        alive = false;
    }
    bool is_alive()
    {
        return alive;
    }
    void set_x(const int & x)
    {
        rect.x = x;
    }
    void set_y(const int & y)
    {
        rect.y = y;
    }
    int get_x()
    {
        return rect.x;
    }
    int get_y()
    {
        return rect.y;
    }
    int get_w()
    {
        return rect.w;
    }
    Image & get_image()
    {
        return image;
    }
    Rect & get_rect()
    {
        return rect;
    }
private:
    Image image;
    Rect rect;
    bool alive;
};

class Laser
{
public:
    static const int R = 255;
    static const int G = 255;
    static const int B = 0;
    static const int W = 2;
    static const int H = 4;
    Laser(int x0, int y0)
        : x(x0), y(y0), exist(false)
    {}
    Laser()
    {
        (*this) = Laser(0, 0);
    }
    void set_position(Galaxip & g)
    {
        x = g.get_x() + g.get_w() / 2;
        y = g.get_y();
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
    bool operator==(Rect & r)
    {
        if (x > r.x && x < r.x + r.w &&
            y > r.y && y < r.y + r.h)
        {
            return true;
        }
        return false;
    }
private:
    int x;
    int y;
    bool exist;
};

#endif
