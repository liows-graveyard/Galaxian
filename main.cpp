// Galaxian

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <sstream>

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"
#include "Ships.h"

bool intro()
{
    
    Surface surface(W, H);
	Event event;

	Font title_font("fonts/Nintendo.ttf", 70);
	Color c0 = {0, 255, 0};
	Image title(title_font.render("Galaxian", c0));
	Rect rect_title = title.getRect();

    Font text_font("fonts/Nintendo.ttf", 18);
	Color c1 = {255, 255, 255};
	Image author(text_font.render("Created by: Seth Kasmann", c1));
	Rect rect_author = author.getRect();

    Font points_font("fonts/Nintendo.ttf", 14);
    Color c2 = {0, 255, 255};
    Image points(points_font.render("Convoy     Charger", c2));
    Rect rect_points = points.getRect();

    Image sat(text_font.render("- Score Advance Table -", c1));
    Rect rect_sat = sat.getRect();

    Image points0(points_font.render("60         150  pts", c2));
    Rect rect_points0 = points0.getRect();
    Image points1(points_font.render("50         100  pts", c2));
    Rect rect_points1 = points1.getRect();
    Image points2(points_font.render("40          80  pts", c2));
    Rect rect_points2 = points2.getRect();
    Image points3(points_font.render("30          60  pts", c2));
    Rect rect_points3 = points3.getRect();

    rect_title.x = 45;
	rect_title.y = 75;
	rect_author.x = 20;
	rect_author.y = 450;
    rect_sat.x = 100;
    rect_sat.y = 240;
    rect_points.x = 190;
    rect_points.y = 270;
    rect_points0.x = 225;
    rect_points0.y = 295;
    rect_points1.x = 225;
    rect_points1.y = 320;
    rect_points2.x = 225;
    rect_points2.y = 345;
    rect_points3.x = 225;
    rect_points3.y = 370;

    Image flag_ship("images/galaxian/GalaxianFlagship.gif");
    Rect rect_flag_ship = flag_ship.getRect();
    Image red_alien("images/galaxian/GalaxianRedAlien.gif");
    Rect rect_red_alien = flag_ship.getRect();
    Image purple_alien("images/galaxian/GalaxianPurpleAlien.gif");
    Rect rect_purple_alien = flag_ship.getRect();
    Image aqua_alien("images/galaxian/GalaxianAquaAlien.gif");
    Rect rect_aqua_alien = flag_ship.getRect();

    rect_flag_ship.x = 645;
	rect_flag_ship.y = 285;
    rect_red_alien.x = 645;
	rect_red_alien.y = 310;
    rect_purple_alien.x = 645;
	rect_purple_alien.y = 335;
    rect_aqua_alien.x = 645;
	rect_aqua_alien.y = 360;
    
    int dx = 3;
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    while (1)
	{
        KeyPressed keypressed = get_keypressed();
        if (keypressed[SPACE])
        {
            return true;
        }
		if (event.poll() && event.type() == QUIT)
        {
            return false;
        }

        if (rect_flag_ship.x > 150)
        {
            rect_flag_ship.x -= dx;
        }
        if (rect_red_alien.x > 150 &&
            rect_flag_ship.x <= 300)
        {
            rect_red_alien.x -= dx;
        }
        if (rect_purple_alien.x > 150 &&
            rect_red_alien.x <= 300)
        {
            rect_purple_alien.x -= dx;
        }
        if (rect_aqua_alien.x > 150 &&
            rect_purple_alien.x <= 300)
        {
            rect_aqua_alien.x -= dx;
        }
	
        
		surface.lock();
		surface.fill(BLACK);
        surface.put_image(title, rect_title);
        surface.put_image(author, rect_author);
        surface.put_image(sat, rect_sat);
        surface.put_image(points, rect_points);
        surface.put_image(points0, rect_points0);
        surface.put_image(points1, rect_points1);
        surface.put_image(points2, rect_points2);
        surface.put_image(points3, rect_points3);

        if (rect_points0.w - counter * dx >= 0)
        {
            if (rect_flag_ship.x <= 210 + rect_points0.w)
            {
                surface.put_rect(rect_points0.x, rect_points0.y,
                                 rect_points0.w - counter * dx, rect_points0.h,
                                 256, 256, 256);
                counter++;
            }
            else
            {
                surface.put_rect(rect_points0.x, rect_points0.y,
                                 rect_points0.w, rect_points0.h,
                                 256, 256, 256);
            }
        }
        if (rect_points1.w - counter1 * dx >= 0)
        {
            if (rect_red_alien.x <= 210 + rect_points0.w)
            {
                surface.put_rect(rect_points1.x, rect_points1.y,
                                 rect_points1.w - counter1 * dx, rect_points1.h,
                                 256, 256, 256);
                counter1++;
            }
            else
            {
                surface.put_rect(rect_points1.x, rect_points1.y,
                                 rect_points1.w, rect_points1.h,
                                 256, 256, 256);
            }
        }
        if (rect_points2.w - counter2 * dx >= 0)
        {
            if (rect_purple_alien.x <= 210 + rect_points2.w)
            {
                surface.put_rect(rect_points2.x, rect_points2.y,
                                 rect_points2.w - counter2 * dx, rect_points2.h,
                                 256, 256, 256);
                counter2++;
            }
            else
            {
                surface.put_rect(rect_points2.x, rect_points2.y,
                                 rect_points2.w, rect_points2.h,
                                 256, 256 , 256);
            }
        }
        if (rect_points3.w - counter3 * dx >= 0)
        {
            if (rect_aqua_alien.x <= 210 + rect_points3.w)
            {
                surface.put_rect(rect_points3.x, rect_points3.y,
                                 rect_points3.w - counter3 * dx, rect_points3.h,
                                 256, 256 , 256);
                counter3++;
            }
            else
            {
                surface.put_rect(rect_points3.x, rect_points3.y,
                                 rect_points3.w, rect_points3.h,
                                 256, 256 , 256);
            }
        }

        surface.put_image(flag_ship, rect_flag_ship);
        if (rect_flag_ship.x <= 250)
        {
            surface.put_image(red_alien, rect_red_alien);
        }
        if (rect_red_alien.x <= 250)
        {
            surface.put_image(purple_alien, rect_purple_alien);
        }
        if (rect_purple_alien.x <= 250)
        {
            surface.put_image(aqua_alien, rect_aqua_alien);
        }
		surface.unlock();
		surface.flip();

		delay(20);
	}
}

void game()
{
 
    Surface surface(W, H);
	Event event;
    AquaAlien aqua[SHIPS_MAX];
    PurpleAlien purple[SHIPS_MAX];
    RedAlien red[SHIPS_MAX];
    FlagShip flagship[SHIPS_MAX];
    Galaxip startship;
    Laser laser[LSR_MAX];
    int x = 100;
    int y = 60;
    int dx = 2;
    bool left = true;
    int laser_counter = 1;

    startship.set_x(320);
    startship.set_y(400);

    while (1)
    {
        if (event.poll() && event.type() == QUIT) break;

        surface.lock();
		surface.fill(BLACK);
        int t = x;
        for (int i = 0; i < 10; i++)
        {
            if (flagship[i].is_alive())
            {
                flagship[i].set_x(t);
                flagship[i].set_y(y);
                surface.put_image(flagship[i].get_image(),
                                  flagship[i].get_rect());
            }
            if (red[i].is_alive())
            {
                red[i].set_x(t);
                red[i].set_y(y + 30);
                surface.put_image(red[i].get_image(),
                                  red[i].get_rect());
            }
            if (purple[i].is_alive())
            {
                purple[i].set_x(t);
                purple[i].set_y(y + 60);
                surface.put_image(purple[i].get_image(),
                                  purple[i].get_rect());
            }
            if (aqua[i].is_alive())
            {
                aqua[i].set_x(t);
                aqua[i].set_y(y + 90);
                surface.put_image(aqua[i].get_image(),
                                  aqua[i].get_rect());
            }
            t += 44;
        }
        if (startship.is_alive())
        {
            KeyPressed keypressed = get_keypressed();
            if (keypressed[LEFTARROW])
            {
                if (startship.get_x() >= 40)
                {
                    startship.set_x(startship.get_x() - 3);
                }
            }
            else if (keypressed[RIGHTARROW])
            {
                if (startship.get_x() <= 600)
                {
                    startship.set_x(startship.get_x() + 3);
                }
            }
            surface.put_image(startship.get_image(),
                              startship.get_rect());
        }
        
        //--------------------------------------
        // TESTING LASERS
        //--------------------------------------
        KeyPressed keypressed = get_keypressed();
        if (keypressed[SPACE] && laser_counter == 0)
        {
            for (int i = 0; i < LSR_MAX; i++)
            {
                if (!laser[i].get_exist())
                {
                    laser[i].set_exist(1);
                    laser[i].set_position(startship);
                    laser_counter = 3;
                    break;
                }
            }
        }
        for (int i = 0; i < LSR_MAX; i++)
        {
            if (laser[i].get_exist())
            {
                if (laser[i].get_y() < 0)
                {
                    laser[i].set_exist(0);
                }
                surface.put_rect(laser[i].get_x(), laser[i].get_y(),
                                 laser[i].W, laser[i].H,
                                 laser[i].R, laser[i].G, laser[i].B);
                laser[i].set_y(laser[i].get_y() - 4);
                //--------------------------------------
                // Laser hitting a ship logic
                //--------------------------------------
                for (int j = 0; j < SHIPS_MAX; j++)
                {
                    if (laser[i] == aqua[j].get_rect() &&
                        aqua[j].is_alive())
                    {
                        aqua[j].kill();
                        laser[i].set_exist(false);
                        break;
                    }
                    if (laser[i] == purple[j].get_rect()&&
                        purple[j].is_alive())
                    {
                        purple[j].kill();
                        laser[i].set_exist(false);
                        break;
                    }
                    if (laser[i] == red[j].get_rect()&&
                        red[j].is_alive())
                    {
                        red[j].kill();
                        laser[i].set_exist(false);
                        break;
                    }
                    if (laser[i] == flagship[j].get_rect()&&
                        flagship[j].is_alive())
                    {
                        flagship[j].kill();
                        laser[i].set_exist(false);
                        break;
                    }
                }
            }
        }
        if (laser_counter > 0 && !keypressed[SPACE])
        {
            laser_counter--;
        }
        //--------------------------------------
        // END OF LASER TEST
        //--------------------------------------
        
        if (x == 10)
        {
            left = false;
        }
        if (x == 190)
        {
            left = true;
        }
        
        if (left)
        {
            x -= dx;
        }
        else
        {
            x += dx;
        }
        
		surface.unlock();
		surface.flip();

        delay(20);
    }
}

int main()
{
    if (intro())
    {
        game();
    }
    
    return 0;
}
