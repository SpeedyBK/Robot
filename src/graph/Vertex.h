//
// Created by Benja on 6/24/2022.
//

#ifndef ROBOT_VERTEX_H
#define ROBOT_VERTEX_H

#include <iostream>

using namespace std;

namespace RobbyTheRobot {

    class Vertex {

    public:

        explicit Vertex(int id);

        ~Vertex() = default;

        int get_id() const { return this->id; }

        string get_name() const { return this->name; }

        int get_minerals() const { return this->amount_of_minerals; }

        pair<int, int> get_position() { return this->position; };

        void set_position(pair<int, int> postion) { this->position = postion; }

        void set_minerals(int minerals) { this->amount_of_minerals = minerals; }

        bool operator<(const Vertex &vref) const { return id < vref.id; }

        void print_vertex();

    private:

        string name;

        int id;

        int amount_of_minerals;

        pair<int, int> position;

    };

    ostream& operator<<(ostream& os, const Vertex& v);

}

#endif //ROBOT_VERTEX_H
