//
// Created by benjamin on 09.07.22.
//

#include "Dispatcher.h"
#include "../graph/Edge.h"
#include <set>

namespace RobbyTheRobot {

    Dispatcher::Dispatcher(World* w, Display* d, double hFactor) : w(w), aStar(d, w, hFactor) {
        this->d = d;
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
            double pathCost = aStar.getPathTime();
            set<Vertex*> vsd = {FactoryVertex, v};
            g.create_edge(vsd, pathCost);
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

    void Dispatcher::vis() {

        auto win_ptr = d->getWindowPtr();

        dStates dstate = dStates::drawStaticStuff;

        while (win_ptr->isOpen()) {
            sf::Event event;
            while (win_ptr->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    win_ptr->close();
                }
            }

            switch (dstate) {
                case dStates::drawStaticStuff:
                    d->draw_times();
                    d->draw_minerals();
                    d->draw_factory();
                    win_ptr->display();
                    dstate = dStates::empty;
                    break;
                case dStates::empty:
                    break;
            }
        }
    }

}
