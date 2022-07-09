//
// Created by Benja on 6/24/2022.
//

#include "Vertex.h"

namespace RobbyTheRobot {

    Vertex::Vertex(int id) : id(id) {

        this->name = "Vertex_" + to_string(id);
        this->position = {0, 0};
        this->amount_of_minerals = 0;

    }

    void Vertex::print_vertex() {
        cout << name << " Position: " << position.getX() << "/"
             << position.getY() << " Mineralcount: " << amount_of_minerals << endl;
    }

    ostream &operator<<(ostream &os, const Vertex &v) {
        os << "Vertex:" << v.get_name() << "(ID " << to_string(v.get_id()) << ")";

        return os;
    }

}