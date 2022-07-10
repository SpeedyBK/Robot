//
// Created by Benja on 6/24/2022.
//

#ifndef ROBOT_EDGE_H
#define ROBOT_EDGE_H

#include <iostream>
#include <deque>
#include <set>

#include "Vertex.h"
#include "../WorldUtils/Vector2i.h"

using namespace std;

namespace RobbyTheRobot {

    class Edge {

    public:

        Edge(set<Vertex*> &vsd, double distance, int id);

        set<Vertex*> get_vertices_of_edge() const { return vsd; }

        int get_id() const { return this->id; }

        double get_distance() const { return this->distance; }

        string get_name() const { return this->name; }

    private:

        set<Vertex*> vsd;

        double distance;

        string name;

        int id;

    };

    ostream& operator<<(ostream& os, const Edge& e);

}

#endif //ROBOT_EDGE_H
