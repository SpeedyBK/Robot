//
// Created by benjamin on 09.07.22.
//

#ifndef ROBOT_DISPATCHER_H
#define ROBOT_DISPATCHER_H

#include <memory>
#include <map>

#include "../World.h"
#include "../graph/Graph.h"
#include "../WorldUtils/AStarSearch.h"

namespace RobbyTheRobot {

    using namespace std;

    enum class dStates{drawStaticStuff, empty};

    class Dispatcher {

    public:

        Dispatcher(World* w, Display* d, double hFactor);

        ~Dispatcher() = default;

        void createFactoryToMinsPaths();

        void printPathCosts();

        void vis();

    private:

        World* w;

        Display* d;

        AStarSearch aStar;

        Graph g;

        Vertex* FactoryVertex;

        map<Vector2i, Vertex*> coordinatesToVertexMap;
    };
}


#endif //ROBOT_DISPATCHER_H
