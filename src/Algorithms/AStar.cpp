//
// Created by Benja on 6/25/2022.
//

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

}
