//
// Created by benjamin on 09.07.22.
//

#ifndef ROBOT_DISPATCHER_H
#define ROBOT_DISPATCHER_H

#include <memory>

#include "../World.h"
#include "../graph/Graph.h"
#include "../WorldUtils/AStarSearch.h"

namespace RobbyTheRobot {

    using namespace std;

    class Dispatcher {

    public:

        Dispatcher(World* w, double hFactor);

        ~Dispatcher() = default;

        void createFactoryToMinsPaths();

        void printPathCosts();

    private:

        World* w;

        AStarSearch aStar;

        Graph g;

        Vertex* FactoryVertex;

    };
}


#endif //ROBOT_DISPATCHER_H
