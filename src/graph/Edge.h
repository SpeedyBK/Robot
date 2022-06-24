//
// Created by Benja on 6/24/2022.
//

#ifndef ROBOT_EDGE_H
#define ROBOT_EDGE_H

#include <iostream>

#include "Vertex.h"

using namespace std;

namespace RobbyTheRobot {

    class Edge {

    public:

        Edge( pair<Vertex*, Vertex*> vsd, int distance, int id);

        pair<Vertex*, Vertex*> get_vertices_of_edge() const { return vsd; }

        int get_id() const { return this->id; }

        int get_distance() const { return this->distance; }

        string get_name() const { return this->name; }

    private:

        pair<Vertex*, Vertex*> vsd;

        int distance;

        string name;

        int id;

    };

    ostream& operator<<(ostream& os, const Edge& e);

}

#endif //ROBOT_EDGE_H