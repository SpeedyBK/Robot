//
// Created by benjamin on 05.07.22.
//

#ifndef ROBOT_ASTARSEARCH_H
#define ROBOT_ASTARSEARCH_H

#include <set>
#include "AStarNode.h"
#include "Vector2i.h"
#include "../Display.h"
#include "FibonacciHeap.h"

namespace RobbyTheRobot {

    using namespace std;

    class AStarSearch {

    public:

        AStarSearch(Display* dp, shared_ptr<World> wp, Vector2i start, Vector2i end);

        ~AStarSearch() = default;

        void startEndTest();

        void findPath();

    private:

        void expandNode(AStarNode node, FibonacciHeap<AStarNode>& oL, set<AStarNode>& cL);

        void visDistance(Vector2i& start, Vector2i& end);

        void visualize(Vector2i coordinates, int blue, int green);

        static double getDistance(Vector2i& a, Vector2i& b);

        Vector2i start;

        Vector2i end;

        Display* d;

        shared_ptr<World> wp;

    };
}

#endif //ROBOT_ASTARSEARCH_H
