//
// Created by benjamin on 07.07.22.
//

#include <vector>
#include <ctime>
#include <iomanip>

#include "../World.h"
#include "../WorldUtils/AStarSearch.h"
#include "Tests.h"
#include "../graph/Graph.h"
#include "../Dispatcher/Dispatcher.h"

namespace RobbyTheRobot {

    bool Tests::aStarTest() {
        try {
            cout << "A-Star Test:" << endl;
            int n = 1000;
            auto W = World(n);
            AStarSearch aStar(nullptr, &W);
            clock_t start, end;
            cout << "   " << "Creating all Nodes.." << endl;
            start = clock();
            aStar.createAllNodes();
            end = clock();
            cout << "   " << "Done in " << fixed << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec "
                 << endl << endl;
            cout << "   " << "Searching path with PQ from 1/1 to " << n - 1 << "/" << n - 1 << ".." << endl;
            start = clock();
            aStar.findPathPQ({1, 1}, {n - 1, n - 1});
            end = clock();
            cout << "   " << "Done in " << fixed << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec "
                 << endl << "   " << "Total Cost: " << aStar.getPathAndTime().second << endl << endl;
            cout << "   " << "Resetting all Nodes.." << endl;
            start = clock();
            aStar.resetAll();
            end = clock();
            cout << "   " << "Done in " << fixed << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec "
                 << endl << endl;
        } catch (...) {
            return false;
        }
        return true;
    }

    bool Tests::graphTest() {
        try {
            cout << "Graph Test:" << endl;
            int n = 15;
            World w(n);
            clock_t start = clock();
            Graph g;
            g.create_vertices_from_map(w.get_material_map());
            g.create_factory_vertex(w.get_factory_position().getX(), w.get_factory_position().getY());
            for (auto &v: g.Vertices()) {
                cout << "   ";
                v->print_vertex();
            }
            cout << endl;
            g.create_complete_graph_test();
            for(auto &e : g.Edges()){
                cout << "   " << e->get_name() << ": ";
                for (auto &v : e->get_vertices_of_edge()){
                    cout << v->get_name() << " ";
                }
                cout << e->get_distance() << endl;
            }
            clock_t end = clock();
            cout << "   " << "Done in " << fixed << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec "
                 << endl << endl;
        }catch (...){
            return false;
        }
        return true;
    }

    bool Tests::dispatchTest() {
        try {
            int n = 600;
            World w(n);
            clock_t start = clock();
            Dispatcher dis(&w);
            dis.createFactoryToMinsPaths();
            dis.printPathCosts();
            clock_t end = clock();
            cout << "   " << "Done in " << fixed << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(5)
                 << " sec "
                 << endl << endl;
        }catch (...){
            return false;
        }
        return true;
    }
}
