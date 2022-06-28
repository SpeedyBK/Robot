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

        void find_path(vector<int> &start_end);

        list<pair<int, int>> get_path(vector<int> start_end);

        int get_path_distance(vector<int> start_end);

    private:

        static double get_distance(vector<int>& start_end);

        class node{

        public:

            node(){
                this->_coordinates = {0,0};
                this->_parent_node = nullptr;
                this->_g = 0;
                this->_h = 0;
                this->_f = _h + _g;
                has_minerals = false;
            };

            node(pair<int, int> coordinates, node* parrent, double g, double h){
                this->_coordinates = coordinates;
                this->_parent_node = parrent;
                this->_g = g;
                this->_h = h;
                this->_f = h + g;
                has_minerals = false;
            }

            void set_minerals(bool has_mins){ this->has_minerals = has_mins; }

            bool has_minerals;
            node* _parent_node;
            pair<int, int> _coordinates;
            double _g;
            double _h;
            double _f;
        };

        World* w;

        map<vector<int>, list<pair<int, int>>> path_map;

        map<vector<int>, int> cost_map;

        list<node>path;

    };
}

#endif //ROBOT_ASTAR_H
