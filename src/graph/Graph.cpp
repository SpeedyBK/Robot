//
// Created by Benja on 6/24/2022.
//

#include <memory>
#include "Graph.h"
#include "../Exception.h"

namespace RobbyTheRobot {

    Graph::Graph() {

        this->max_vertex_id = 0;
        this->name = "";

    }

    Graph::~Graph() {
        for (Vertex *v : Vertices()) { delete v; }
        for (Edge *e : Edges()) { delete e; }
    }

    Vertex &Graph::create_vertex() {
        return create_vertex(++max_vertex_id);
    }

    Vertex &Graph::create_vertex(int id) {
        for (auto &it : Vertices()) {
            Vertex *v = it;
            if (v->get_id() == id) throw RobbyTheRobot::Exception(
                        "Graph.createVertex: Error! This id is already occupied: " + to_string(id) + "( " +
                        v->get_name() + " )");
        }
        auto *v = new Vertex(id);
        vertices.insert(v);
        vertex_of_id.insert(make_pair(id, v));

        //keep maxVertexId consistent
        if (this->max_vertex_id < v->get_id()){
            this->max_vertex_id++;
        }
        return *v;
    }

    void Graph::create_vertices_from_map(vector<vector<int>>&world_map) {
        int y = 0;
        for (auto &y_it : world_map){
            int x = 0;
            for(auto &x_it : y_it){
                if (x_it > 0){
                    Vertex &v = create_vertex();
                    v.set_minerals(x_it);
                    v.set_position(std::make_pair(x, y));
                }
                x++;
            }
            y++;
        }
    }

    ostream &operator<<(ostream &os, const Graph &g) {
        os << "------------------------------------------------------------------------------------" << endl;
        os << "---------------------------------- Graph Model -------------------------------------" << endl;
        os << "------------------------------------------------------------------------------------" << endl;

        for (auto &a : g.vertices) {
            Vertex *v = a;
            os << *v << endl;
        }

        for (auto &a : g.edges) {
            Edge *e = a;
            os << *e << endl;
        }
        return os;
    }

    Edge &Graph::create_edge(set<Vertex*> vsd, int distance) {
        Edge *e = new Edge(vsd, distance, (int)edges.size() + 1);

        for (auto &it : Edges() ) {
            Edge *eIt = it;

            if (e->get_id() == eIt->get_id())
                throw RobbyTheRobot::Exception(
                        "Graph.createEdge: Error! This edge id is already occupied: " + to_string(e->get_id()));
        }

        edges.insert(e);
        return *e;
    }

    void Graph::create_complete_graph_test() {
        for (int i = 1; i <= max_vertex_id; i++){
            for (int j = i + 1; j <= max_vertex_id; j++){
                create_edge({get_vertex_by_id(i), get_vertex_by_id(j)}, 42);
            }
        }
    }

    void Graph::create_factory_vertex(int x, int y) {
        Vertex &v = create_vertex();
        v.set_position(std::make_pair(x, y));
        v.set_minerals(0);
    }
}

