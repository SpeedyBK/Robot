//
// Created by Benja on 6/21/2022.
//

#ifndef ROBOT_DISPLAY_H
#define ROBOT_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "World.h"
#include "WorldUtils/Vector2i.h"
#include "graph/Graph.h"

using namespace std;

namespace RobbyTheRobot {

    class Display {

    public:

        explicit Display(World* wp);

        ~Display() { delete this->window_ptr; }

        void calc_line(Vector2i& start, Vector2i& end);

        sf::RenderWindow* getWindowPtr() const;

        void drawVisitedFields(sf::RenderWindow* win_ptr, Vector2i fieldVector, int green, int blue);

        void draw_times();

        void draw_minerals();

        void draw_robot();

        void draw_factory();

        void clearScreen();

        void draw_line(Vector2i start, Vector2i end);

    private:

        World* wp;

        shared_ptr<Graph> G;

        sf::RenderWindow *window_ptr;

        int width;
        int heigth;

        int scaling_factor;

    };

}

#endif //ROBOT_DISPLAY_H
