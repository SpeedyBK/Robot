//
// Created by Benja on 6/24/2022.
//

#include "Edge.h"
namespace RobbyTheRobot {

    Edge::Edge(set<Vertex*> &vsd, int distance, int id) {
        this->id = id;
        this->name = "Edge_" + to_string(id);
        this->vsd = vsd;
        this->distance = distance;
    }

    ostream &operator<<(ostream &os, const Edge &e) {
        os << "Edge Id: " << e.get_id() << ". Connected Nodes: ";
        for (auto &it : e.get_vertices_of_edge()){
            os << it->get_name() << " ";
        }
        os << "Distance " << e.get_distance();
        return os;
    }

}