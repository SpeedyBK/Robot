//
// Created by Benja on 6/22/2022.
//

#ifndef ROBOT_ROBOT_H
#define ROBOT_ROBOT_H

#include "World.h"

class World;

class Robot {

public:

    Robot(int x, int y, World* w);

    ~Robot();

    std::pair<int, int> get_position();

    bool move_left();

    bool move_right();

    bool move_up();

    bool move_down();

    void gather_materials();

    void unload_materials();

private:

    const int MAX_CAPACITY = 3;

    int n;
    int x;
    int y;

    int materials;

    World* w;

};


#endif //ROBOT_ROBOT_H
