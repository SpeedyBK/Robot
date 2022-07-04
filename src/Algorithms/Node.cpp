//
// Created by benjamin on 04.07.22.
//

#include "Node.h"

namespace RobbyTheRobot {

    Node::Node() {
        this->_coordinates = {0, 0};
        this->_parent_node = nullptr;
        this->_g = 0;
        this->_h = 0;
        this->_f = _h + _g;
        has_minerals = false;
    }

    Node::Node(std::pair<int, int> coordinates, RobbyTheRobot::Node *parrent, double g, double h) {
        this->_coordinates = coordinates;
        this->_parent_node = parrent;
        this->_g = g;
        this->_h = h;
        this->_f = h + g;
        has_minerals = false;
    }

    bool operator<(const Node &a, const Node &b) {
        return a._f < b._f;
    }

}
