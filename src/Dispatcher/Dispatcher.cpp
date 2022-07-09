//
// Created by benjamin on 09.07.22.
//

#include "Dispatcher.h"
#include "../graph/Edge.h"
#include <set>

namespace RobbyTheRobot {

    Dispatcher::Dispatcher(World* w) : w(w), aStar(nullptr, w) {
        this->g.create_vertices_from_map(w->get_material_map());
        this->FactoryVertex = &this->g.create_factory_vertex(w->get_factory_position().getX(), w->get_factory_position().getY());
    }

    void Dispatcher::createFactoryToMinsPaths() {

        aStar.createAllNodes();
        int i = 0;
        for (auto &v : g.Vertices()){
            if (v == FactoryVertex){
                continue;
            }
            aStar.findPathPQ(FactoryVertex->get_position(), v->get_position());
            auto pathAndCost = aStar.getPathAndTime();
            set<Vertex*> vsd = {FactoryVertex, v};
            g.create_edge(vsd, pathAndCost.second, pathAndCost.first);
            aStar.resetAll();
            cout << i << ": Path Done" << endl;
            i++;
        }

    }

    void Dispatcher::printPathCosts() {
        double totalCost = 0;
        for (auto &e: g.Edges()){
            cout << *e << endl;
            totalCost += e->get_distance();
        }
        cout << "Total Cost: " << totalCost << endl;
    }

}
