//
// Created by Benja on 6/21/2022.
//

#ifndef ROBOT_DISPLAY_H
#define ROBOT_DISPLAY_H

#include <SFML/Graphics.hpp>
#include "World.h"

class Display {

public:

    explicit Display(World* w);

    void draw();

private:

    void draw_times(sf::RenderWindow* win_ptr);

    void draw_minerals(sf::RenderWindow* win_ptr);

    void draw_robot(sf::RenderWindow* win_ptr);

    void draw_factory(sf::RenderWindow* win_ptr);

    World* W;

    int width;
    int heigt;

    int scaling_factor;

};


#endif //ROBOT_DISPLAY_H
