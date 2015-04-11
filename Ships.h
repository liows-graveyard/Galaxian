#ifndef SHIPS_H
#define SHIPS_H

#include "Image.h"
#include "Rect.h"
#include "Event.h"
#include "EnemyLaser.h"

const int LSR_MAX = 30;
const int SHIPS_MAX = 10;
const int ENEMY_SPACING = 44;
const int GALAXIP_SPEED = 4;
const int ENEMY_FIRE_FREQUENCY = 500;
// the above variable can also be inserted into the classes.
// this would allow the aliens to fire at different speeds.

class Galaxip
{
public:
    Galaxip()
        : image("images/galaxian/GalaxianGalaxip.gif"),
          rect(image.getRect()), alive(true)
    {
        rect.x = 320;
        rect.y = 400;
    }
    void kill()
    {
        alive = false;
    }
    bool is_alive()
    {
        return alive;
    }
    void set_alive(const bool & a)
    {
        alive = a;
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
    int get_h()
    {
        return rect.h;
    }
    Image & get_image()
    {
        return image;
    }
    Rect & get_rect()
    {
        return rect;
    }
    void user_input(const KeyPressed & k, Surface & surface)
    {
        if (k[LEFTARROW])
        {
            if (this->get_x() >= 40)
            {
                this->set_x(this->get_x() - GALAXIP_SPEED);
            }
        }
        else if (k[RIGHTARROW])
        {
            if (this->get_x() <= 600)
            {
                this->set_x(this->get_x() + GALAXIP_SPEED);
            }
        }
        surface.put_image(this->get_image(),
                          this->get_rect());
    }
private:
    Image image;
    Rect rect;
    bool alive;
};

class AquaAlien
{
public:
    AquaAlien()
        : image("images/galaxian/GalaxianAquaAlien.gif"),
          rect(image.getRect()), alive(true), attack(false), laser(NULL)
    {}
    ~AquaAlien()
    {
        if (laser != NULL)
        {
            delete laser;
        }
    }
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
    void paint(Surface & surface, const int & x, const int & y, Galaxip & g)
    {
        //----------------------------------------------//
        // Paint the Enemy Laser & Collision Logic
        //----------------------------------------------//
        if (laser != NULL)
        {
            if (laser->get_y() >= g.get_y() &&
                laser->get_x() >= g.get_x() &&
                laser->get_x() + laser->W <= g.get_x() + g.get_w() &&
                laser->get_y() + laser->H <= g.get_y() + g.get_h())
            {
                g.set_alive(false);
                delete laser;
                laser = NULL;
            }
            else if (laser->get_y() > 480)
            {
                delete laser;
                laser = NULL;                
            }
            else
            {
                this->paint_laser(surface);
            }
        }        
        //----------------------------------------------//
        // Paint the Ship
        //----------------------------------------------//
        if (this->is_alive())
        {
            this->set_x(x);
            this->set_y(y + 90);
            surface.put_image(this->get_image(), this->get_rect());
            if (rand() % ENEMY_FIRE_FREQUENCY == 0 &&
                laser == NULL)
            {
                    laser_fire();
            }
        }
    }
    void paint_laser(Surface & surface)
    {
        surface.put_rect(laser->get_x(), laser->get_y(),
                         laser->W, laser->H,
                         laser->R, laser->G, laser->B);
        laser->set_y(laser->get_y() + 4);

        if (laser->get_y() > 480)
        {
            delete laser;
            laser = NULL;
        }
    }
    void laser_fire()
    {
        laser = new EnemyLaser;
        laser->set_x(rect.x + rect.w / 2);
        laser->set_y(rect.y + rect.h);
    }
private:
    Image image;
    Rect rect;
    bool alive;
    bool attack;
    EnemyLaser *laser;
};

class RedAlien
{
public:
    RedAlien()
        : image("images/galaxian/GalaxianRedAlien.gif"),
          rect(image.getRect()), alive(true), attack(false), laser(NULL)
    {}
    ~RedAlien()
    {
        if (laser != NULL)
        {
            delete laser;
        }
    }
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
    void paint(Surface & surface, const int & x, const int & y, Galaxip & g)
    {
        //----------------------------------------------//
        // Paint the Enemy Laser & Collision Logic
        //----------------------------------------------//
        if (laser != NULL)
        {
            if (laser->get_y() >= g.get_y() &&
                laser->get_x() >= g.get_x() &&
                laser->get_x() + laser->W <= g.get_x() + g.get_w() &&
                laser->get_y() + laser->H <= g.get_y() + g.get_h())
            {
                g.set_alive(false);
                delete laser;
                laser = NULL;
            }
            else if (laser->get_y() > 480)
            {
                delete laser;
                laser = NULL;                
            }
            else
            {
                this->paint_laser(surface);
            }
        }        
        //----------------------------------------------//
        // Paint the Ship
        //----------------------------------------------//
        if (this->is_alive())
        {
            this->set_x(x);
            this->set_y(y + 65);
            surface.put_image(this->get_image(), this->get_rect());
            if (rand() % ENEMY_FIRE_FREQUENCY == 0 &&
                laser == NULL)
            {
                    laser_fire();
            }
        }
    }
    void paint_laser(Surface & surface)
    {
        surface.put_rect(laser->get_x(), laser->get_y(),
                         laser->W, laser->H,
                         laser->R, laser->G, laser->B);
        laser->set_y(laser->get_y() + 4);
    }
    void laser_fire()
    {
        laser = new EnemyLaser;
        laser->set_x(rect.x + rect.w / 2);
        laser->set_y(rect.y + rect.h);
    }    
private:
    Image image;
    Rect rect;
    bool alive;
    bool attack;
    EnemyLaser *laser;
};

class PurpleAlien
{
public:
    PurpleAlien()
        : image("images/galaxian/GalaxianPurpleAlien.gif"),
          rect(image.getRect()), alive(true), attack(false), laser(NULL)
    {}
    ~PurpleAlien()
    {
        if (laser != NULL)
        {
            delete laser;
        }
    }
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
    void paint(Surface & surface, const int & x, const int & y, Galaxip & g)
    {
        //----------------------------------------------//
        // Paint the Enemy Laser & Collision Logic
        //----------------------------------------------//
        if (laser != NULL)
        {
            if (laser->get_y() >= g.get_y() &&
                laser->get_x() >= g.get_x() &&
                laser->get_x() + laser->W <= g.get_x() + g.get_w() &&
                laser->get_y() + laser->H <= g.get_y() + g.get_h())
            {
                g.set_alive(false);
                delete laser;
                laser = NULL;
            }
            else if (laser->get_y() > 480)
            {
                delete laser;
                laser = NULL;                
            }
            else
            {
                this->paint_laser(surface);
            }
        }        
        //----------------------------------------------//
        // Paint the Ship
        //----------------------------------------------//
        if (this->is_alive())
        {
            this->set_x(x);
            this->set_y(y + 40);
            surface.put_image(this->get_image(), this->get_rect());
            if (rand() % ENEMY_FIRE_FREQUENCY == 0 &&
                laser == NULL)
            {
                    laser_fire();
            }
        }        
    }
    void paint_laser(Surface & surface)
    {
        surface.put_rect(laser->get_x(), laser->get_y(),
                         laser->W, laser->H,
                         laser->R, laser->G, laser->B);
        laser->set_y(laser->get_y() + 4);
    }
    void laser_fire()
    {
        laser = new EnemyLaser;
        laser->set_x(rect.x + rect.w / 2);
        laser->set_y(rect.y + rect.h);
    }
private:
    Image image;
    Rect rect;
    bool alive;
    bool attack;
    EnemyLaser *laser;
};

class FlagShip
{
public:
    FlagShip()
        : image("images/galaxian/GalaxianFlagship.gif"),
          rect(image.getRect()), alive(true), attack(false), laser(NULL)
    {}
    ~FlagShip()
    {
        if (laser != NULL)
        {
            delete laser;
        }
    }
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
    void paint(Surface & surface, const int & x, const int & y, Galaxip & g)
    {
        //----------------------------------------------//
        // Paint the Enemy Laser & Collision Logic
        //----------------------------------------------//
        if (laser != NULL)
        {
            if (laser->get_y() >= g.get_y() &&
                laser->get_x() >= g.get_x() &&
                laser->get_x() + laser->W <= g.get_x() + g.get_w() &&
                laser->get_y() + laser->H <= g.get_y() + g.get_h())
            {
                g.set_alive(false);
                delete laser;
                laser = NULL;
            }
            else if (laser->get_y() > 480)
            {
                delete laser;
                laser = NULL;                
            }
            else
            {
                this->paint_laser(surface);
            }
        }        
        //----------------------------------------------//
        // Paint the Ship
        //----------------------------------------------//
        if (this->is_alive())
        {
            this->set_x(x);
            this->set_y(y + 15);
            surface.put_image(this->get_image(), this->get_rect());
            if (rand() % ENEMY_FIRE_FREQUENCY == 0 &&
                laser == NULL)
            {
                    laser_fire();
            }
        }
    }
    void paint_laser(Surface & surface)
    {
        surface.put_rect(laser->get_x(), laser->get_y(),
                         laser->W, laser->H,
                         laser->R, laser->G, laser->B);
        laser->set_y(laser->get_y() + 4);
    }
    void laser_fire()
    {
        laser = new EnemyLaser;
        laser->set_x(rect.x + rect.w / 2);
        laser->set_y(rect.y + rect.h);
    }
private:
    Image image;
    Rect rect;
    bool alive;
    bool attack;
    EnemyLaser *laser;
};

struct Aliens
{
    AquaAlien aqua[SHIPS_MAX];
    PurpleAlien purple[SHIPS_MAX];
    RedAlien red[SHIPS_MAX];
    FlagShip flagship[SHIPS_MAX];
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
    bool fire_laser(int & laser_timer, Galaxip & g)
    {
        if (!this->get_exist())
        {
            this->set_exist(1);
            this->set_position(g);
            laser_timer = 3;
            return true;
        }
        return false;
    }
    void laser_print(Surface & surface, Aliens & alien)
    {
        if (this->get_exist())
        {
            if (this->get_y() < 0)
            {
                this->set_exist(0);
            }
            surface.put_rect(this->get_x(), this->get_y(),
                             this->W, this->H,
                             this->R, this->G, this->B);
            this->set_y(this->get_y() - 4);
            //--------------------------------------
            // Laser hitting a ship logic
            //--------------------------------------
            for (int j = 0; j < SHIPS_MAX; j++)
            {
                if ((*this) == alien.aqua[j].get_rect() &&
                    alien.aqua[j].is_alive())
                {
                    alien.aqua[j].kill();
                    this->set_exist(false);
                    break;
                }
                if ((*this) == alien.purple[j].get_rect() &&
                    alien.purple[j].is_alive())
                {
                    alien.purple[j].kill();
                    this->set_exist(false);
                    break;
                }
                if ((*this) == alien.red[j].get_rect() &&
                    alien.red[j].is_alive())
                {
                    alien.red[j].kill();
                    this->set_exist(false);
                    break;
                }
                if ((*this) == alien.flagship[j].get_rect() &&
                    alien.flagship[j].is_alive())
                {
                    alien.flagship[j].kill();
                    this->set_exist(false);
                    break;
                }
            }
        }
    }
private:
    int x;
    int y;
    bool exist;
};

#endif
