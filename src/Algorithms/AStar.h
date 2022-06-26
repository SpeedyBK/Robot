//
// Created by Benja on 6/25/2022.
//

#ifndef ROBOT_ASTAR_H
#define ROBOT_ASTAR_H

#pragma once

#include <iostream>
#include <list>
#include <map>
#include "../World.h"

namespace RobbyTheRobot {

    using namespace std;

    class AStar {

    public:

        explicit AStar(World *w);

        list<pair<int, int>> get_path(vector<int> start_end);

        int get_path_distance(vector<int> start_end);

    private:

        struct node{
            bool has_minerals;
            node* _parent_node;
            pair<int, int> _coordinates;
            int _g;
            int _h;
            int _f;
        };

        World *w;

        map<vector<int>, list<pair<int, int>>> path_map;

        map<vector<int>, int> cost_map;

        list<node>path;

        list<node>unchecked;

        list<node>checked;

    };
}

#endif //ROBOT_ASTAR_H
