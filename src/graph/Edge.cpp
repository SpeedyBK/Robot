//
// Created by Benja on 6/24/2022.
//

#include "Edge.h"
namespace RobbyTheRobot {

    Edge::Edge(pair<Vertex *, Vertex *> vsd, int distance, int id) {
        this->id = id;
        this->name = "Edge_" + to_string(id);
        this->vsd = vsd;
        this->distance = distance;
    }

    ostream &operator<<(ostream &os, const Edge &e) {
        string datatype = "Data";
        os << "Edge Id: " << e.get_id() << ". Connected Nodes: "
           << e.get_vertices_of_edge().first->get_name() << ", " << e.get_vertices_of_edge().second->get_name()
           << " Distance " << e.get_distance();

        return os;
    }

}