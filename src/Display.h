//
// Created by Benja on 6/21/2022.
//

#ifndef ROBOT_DISPLAY_H
#define ROBOT_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "World.h"

using namespace std;

class Display {

public:

    explicit Display(World* w);

    ~Display(){ delete this->window_ptr; }

    void draw();

    void calc_line(vector<int>&start_end);

private:

    void draw_times();

    void draw_minerals();

    void draw_robot();

    void draw_factory();

    void draw_line(int start_x, int start_y, int end_x, int end_y);

    World* W;

    sf::RenderWindow* window_ptr;

    int width;
    int heigt;

    int scaling_factor;

};


#endif //ROBOT_DISPLAY_H
