//
// Created by benjamin on 05.07.22.
//

#ifndef ROBOT_ASTARSEARCH_H
#define ROBOT_ASTARSEARCH_H

#include <deque>
#include "AStarNode.h"
#include "Vector2i.h"
#include "../Display.h"

namespace RobbyTheRobot {

    using namespace std;

    class AStarSearch {

    public:

        AStarSearch(Display* dp, shared_ptr<World> wp, Vector2i start, Vector2i end);

        ~AStarSearch() = default;

        void startEndTest();

        void findPath();

        void setHeuristicFactor(double hF) { this->heuristicFactor = hF; }

    private:

        static bool isInList(Vector2i& coordinates, deque<shared_ptr<AStarNode>>& L);

        void expandNode(const shared_ptr<AStarNode>& currentNode);

        void visDistance(Vector2i& start, Vector2i& end);

        void visualize(Vector2i coordinates, int blue, int green);

        static double getDistance(Vector2i& a, Vector2i& b);

        double heuristicFactor;

        Vector2i start;

        Vector2i end;

        Display* d;

        shared_ptr<World> wp;

        deque<shared_ptr<AStarNode>> openList;

        deque<shared_ptr<AStarNode>> closedList;

    };
}

#endif //ROBOT_ASTARSEARCH_H
