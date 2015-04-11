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
    std::cout << "starting!" << std::endl;
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

void enemy_direction(int & enemy_x_seed, bool & enemies_moving_left, int & enemy_y)
{
    if (enemy_y < 50)
    {
        enemy_y += ENEMY_SPEED;
    }
    else
    {
        if (enemy_x_seed == 10)
        {
            enemies_moving_left = false;
        }
        if (enemy_x_seed == 190)
        {
            enemies_moving_left = true;
        }
        enemies_moving_left ? enemy_x_seed -= ENEMY_SPEED : enemy_x_seed += ENEMY_SPEED;
    }
}

void game()
{
    //----------------------------------------------//
    // Please note:
    //
    // 1. The struct Aliens holds all of the alien
    //    arrays.
    // 2. The laser_timer exists so that lasers can't
    //    be fired too quickly, and the space bar
    //    cannot be held down to fire lasers.
    // 3. enemies_moving_left controls the direction
    //    the aliens are moving in.
    //----------------------------------------------//
    struct Aliens alien;
    Surface surface(W, H);
	Event event;
    Galaxip startship;
    Laser laser[LSR_MAX];
    int enemy_x_seed = 100;
    int enemy_y = 0 - ENEMY_SPACING_Y * 4;;
    int laser_timer = 1;
    int alien_counter = SHIPS_MAX * 4;
    bool enemies_moving_left = true;
    while (1) /**  Loop while the game is playing. **/
    {
        int enemy_x = enemy_x_seed; /** initial x of the first enemy **/
        
        if (event.poll() && event.type() == QUIT || alien.wave > 5) break;

        surface.lock();
		surface.fill(BLACK);

        if (alien_counter > 0)
        {
            for (int i = 0; i < SHIPS_MAX; i++)
            {
                //----------------------------------------------//
                // Draw all of the enemy ships and lasers.
                //----------------------------------------------//
                alien.flagship[i].paint(surface, enemy_x, enemy_y, startship);
                alien.red[i].paint(surface, enemy_x, enemy_y, startship);
                alien.purple[i].paint(surface, enemy_x, enemy_y, startship);
                alien.aqua[i].paint(surface, enemy_x, enemy_y, startship);

                enemy_x += ENEMY_SPACING_X; /** update enemy spacing **/
            }
        }
        else
        {
            for (int i = 0; i < SHIPS_MAX; i++)
            {
                alien.flagship[i].set_alive(true);
                alien.flagship[i].set_laser_speed();
                alien.red[i].set_alive(true);
                alien.red[i].set_laser_speed();
                alien.purple[i].set_alive(true);
                alien.purple[i].set_laser_speed();
                alien.aqua[i].set_alive(true);
                alien.aqua[i].set_laser_speed();
                alien_counter += 4;
            }
            alien.wave++;
            enemy_y = 0 - ENEMY_SPACING_Y * 4;
            enemy_x_seed = 100;
        }
        
        /** Update enemy direction **/
        enemy_direction(enemy_x_seed, enemies_moving_left, enemy_y);

        //----------------------------------------------//
        // Draw the user's ship.
        //----------------------------------------------//
        if (startship.is_alive())
        {
            KeyPressed keypressed = get_keypressed();
            startship.user_input(keypressed, surface);
        }
        
        //----------------------------------------------//
        // Fire lasers.
        //----------------------------------------------//
        KeyPressed keypressed = get_keypressed();
        if (keypressed[SPACE] && laser_timer == 0 && startship.is_alive())
        {
            for (int i = 0; i < LSR_MAX; i++)
            {
                if (laser[i].fire_laser(laser_timer, startship)) break;
            }
        }
        
        //----------------------------------------------//
        // Draw the lasers.
        //----------------------------------------------//
        for (int i = 0; i < LSR_MAX; i++)
        {
            laser[i].laser_print(surface, alien, alien_counter);
        }

        /** Update the laser timer **/
        if (laser_timer > 0 && !keypressed[SPACE])
        {
            laser_timer--;
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
