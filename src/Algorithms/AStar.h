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
#include "Node.h"

namespace RobbyTheRobot {

    using namespace std;

    class AStar {

    public:

        explicit AStar(World *w);

        void find_path(vector<int> &start_end);

        list<pair<int, int>> get_path(vector<int> start_end);

        int get_path_distance(vector<int> start_end);

    private:

        static double get_distance(vector<int>& start_end);

        World* w;

        map<vector<int>, list<pair<int, int>>> path_map;

        map<vector<int>, int> cost_map;

        list<Node>path;

    };
}

#endif //ROBOT_ASTAR_H
