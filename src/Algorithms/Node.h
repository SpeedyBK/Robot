//
// Created by benjamin on 04.07.22.
//

#ifndef ROBOT_NODE_H
#define ROBOT_NODE_H

#include <iostream>

namespace RobbyTheRobot {
    class Node {

    public:

        Node();

        Node(std::pair<int, int> coordinates, Node *parrent, double g, double h);

        void set_minerals(bool has_mins) { this->has_minerals = has_mins; }

        bool has_minerals;
        Node *_parent_node;
        std::pair<int, int> _coordinates;
        double _g;
        double _h;
        double _f;

        friend bool operator<(const Node& a, const Node& b);

    };
}

#endif //ROBOT_NODE_H
