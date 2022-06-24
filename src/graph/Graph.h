//
// Created by Benja on 6/24/2022.
//

#ifndef ROBOT_GRAPH_H
#define ROBOT_GRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

#include "Vertex.h"
#include "Edge.h"

using namespace std;

namespace RobbyTheRobot {

    class Graph {

    public:

        Graph();

        ~Graph();

        Vertex &create_vertex();

        Vertex &create_vertex(int id);

        Edge &create_edge(set<Vertex*>vsd, int distance);

        void create_vertices_from_map(vector<vector<int>>&world_map);

        void create_complete_graph_test();

        friend ostream& operator<<(ostream& os, const Graph& g);

        class Edges {
        public:
            Edges(const std::set<Edge *>::iterator &begin, const std::set<Edge *>::iterator &end) : b(begin), e(end) {}

            std::set<Edge *>::iterator begin() { return b; }

            std::set<Edge *>::iterator end() { return e; }

            std::set<Edge *>::iterator b;
            std::set<Edge *>::iterator e;
        };

        Edges Edges() { return {edges.begin(), edges.end()}; }

        class Vertices {
        public:
            Vertices(const std::set<Vertex *>::iterator &begin, const std::set<Vertex *>::iterator &end) : b(begin),
                                                                                                           e(end) {}

            std::set<Vertex *>::iterator begin() { return b; }

            std::set<Vertex *>::iterator end() { return e; }

            std::set<Vertex *>::iterator b;
            std::set<Vertex *>::iterator e;
        };

        Vertices Vertices() { return {vertices.begin(), vertices.end()}; }

        Vertex* get_vertex_by_id(int id) { return this->vertex_of_id.at(id); }

    private:

        string name;

        int max_vertex_id;

        set<Vertex *> vertices;
        unordered_map<int, Vertex*> vertex_of_id;

        set<Edge *> edges;

    };
}

#endif //ROBOT_GRAPH_H
