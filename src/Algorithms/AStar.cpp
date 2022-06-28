//
// Created by Benja on 6/25/2022.
//

#include <cmath>

#include "AStar.h"

namespace RobbyTheRobot {

    AStar::AStar(World *w) {
        this->w = w;
    }

    list<pair<int, int>> AStar::get_path(vector<int> start_end) {
        return list<pair<int, int>>();
    }

    int AStar::get_path_distance(vector<int> start_end) {
        return 0;
    }

    void AStar::find_path(vector<int> &start_end) {
        list<node>open_list;
        list<node>closed_list;
        node current_node({start_end.at(0), start_end.at(1)}, nullptr, 0, get_distance(start_end));
        open_list.push_back(current_node);
        while (!open_list.empty()) {
            current_node = open_list.front();


            //if distance == 0, return.
        }
    }

    double AStar::get_distance(vector<int> &start_end) {
        int dx = start_end.at(0) - start_end.at(2);
        int dy = start_end.at(1) - start_end.at(3);
        return std::sqrt((dx*dx) - (dy*dy));
    }

}
